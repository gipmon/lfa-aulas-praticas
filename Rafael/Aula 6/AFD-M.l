%{
    #include <stdio.h>
    #include <stdbool.h>
%}

%x A B C D E

%option noyywrap
%option nounput
%option noinput

%%
          BEGIN(A);

<A>a    { BEGIN(B); }
<A>b    { BEGIN(D); }
<A>c    { }

<B>a    { }
<B>b    { BEGIN(C); }
<B>c    { BEGIN(A); }

<C>(a|b)    { BEGIN(D); }
<C>c    { BEGIN(A); }

<D>[abc]    { }

<*>.    { BEGIN(E); }

<<EOF>>     { return YY_START == A || YY_START == B ? true : false; }

%%

const char* alphabet = "abc";

bool M(const char* u)
{
    YY_BUFFER_STATE bs = yy_scan_string(u);
    bool ret = yylex();
    yy_delete_buffer(bs);
    return ret;
}   
