%{
int yylex(void);
int yyerror(char *s);
#include <stdio.h>
%}

%%

S   : L
    ;

L   : /* \lambda */
    | E   '\n'  { printf(" --> a valid word\n"); } L
    | '\n' { printf(" --> an empty word\n"); }  L
    | error '\n' { printf(" --> an invalid word\n"); } L
    ;

E   : T
    | E '+' T
    | E '-' T
    ;

T   : F
    | T '*' F
    | T '/' F
    ;

F   : SP N SP
    | SP '(' E ')' SP
    ;

N   : R
    | R N
    ;

D   : '0'
    | '1'
    | '2'
    | '3'
    | '4'
    | '5'
    | '6'
    | '7'
    | '8'
    | '9'
    ;

R   : D
    | D '.' D
    | D ',' D
    ;

SP  : /* \lambda */
    | ' ' SP
    ;

%%

int main(void)
{
    yyparse();
    return 0;
}

int yylex(void)
{
    return getchar();
}

int yyerror(char *s)
{
    return 0;
}
