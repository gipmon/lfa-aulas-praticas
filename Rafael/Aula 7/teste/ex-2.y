%{
int yylex(void);
int yyerror(char *s);
#include <stdio.h>
%}

%%

S   : L
    ;

L   : /* \lambda */
    | P   '\n'  { printf(" --> a valid word\n"); } L
    | error '\n' { printf(" --> an invalid word\n"); } L
    ;

P   :    '{' L '}'
    |    /* \lambda */
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
