%{
    #include <stdio.h>

    static int flag;
%}

%x A B C D E

%option noyywrap

%%
            BEGIN(A);

<A>a    { BEGIN(B); ECHO; }
<A>b    { BEGIN(D); ECHO; }
<A>c    { ECHO; }

<B>a    { ECHO; }
<B>b    { BEGIN(C); ECHO; }
<B>c    { BEGIN(A); ECHO; }

<C>(a|b)    { BEGIN(D); ECHO; }
<C>c    { BEGIN(A); ECHO; }

<D>[abc]    { ECHO; }

<*>.    { BEGIN(E); ECHO; }

<A,B>\n     { fprintf(yyout, " : pertence a L1\n"); BEGIN(A);}
<C,D>\n     { fprintf(yyout, " : não pertence a L1\n"); BEGIN(A);}
<E>\n     { fprintf(yyout, " : contém símbolos inválidos\n"); BEGIN(A);}

<<EOF>>     { return 0; }

%%

int main()
{
    return yylex();
}   
