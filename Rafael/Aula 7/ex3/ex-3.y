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
    ;

T   : F
    | T '.' F
    ;

F   : SP K SP
    | SP '~' F
    ;

K   : '0'
    | '1'
    | '(' E ')'
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
