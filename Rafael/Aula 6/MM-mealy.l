%{
    #include <stdio.h>
    #include <stdbool.h>

    static char* sout;
%}

%x DDD EDD EED ERR

%option noyywrap
%option nounput
%option noinput

%%
            int i = 0;
            BEGIN(DDD);

<DDD>e    { sout[i++] = 'e'; BEGIN(EDD); }
<DDD>d    { sout[i++] = 'e'; BEGIN(EED); }

<EDD>e    { sout[i++] = 'c'; BEGIN(DDD); }

<*>.    { BEGIN(ERR); }

<<EOF>>     { sout[i] = '\0'; return YY_START == ERR; }

%%

const char* inputAlphabet = "ed";

void mealy(const char* u, char* v)
{
    YY_BUFFER_STATE bs = yy_scan_string(u);
    sout = v;
    yylex();
    yy_delete_buffer(bs);
    return;
}
