%{
    #include <stdio.h>

    void printClass(const char* class, const char* text)
    {
        fprintf(yyout, "<span class=\"%s\">%s</span>", class, text);
    }
%}

%option noyywrap

comments    ("/*"[^*]*"*")([^/][^*]*"*")*("/")
type_values (short|int|double|float|unsigned|char|typedef|signed)
keyword     (for|while|switch|case|break|default|if|endif|else|return|extern|do)
constant    (_|[A-Z^e]+[0-9]*)+
string      "\""[^"]"\""
var_names   [_a-zA-Z0-9]+
directive   #[ \t]*[_a-zA-Z0-9]+
/* [não é preciso usar \] [abc] ou a ou b ou c*/

%%

"<"     { fprintf(yyout, "&lt;"); }
">"     { fprintf(yyout, "&gt;"); }
"&"     { fprintf(yyout, "&amp;"); }

{comments} { printClass("comments", yytext); }
{type_values} { printClass("type_values", yytext); }
{keyword} { printClass("keyword", yytext); }
{string} { printClass("string", yytext); }
{constant} { printClass("constant", yytext); }
{var_names} { printClass("var_names", yytext); }
{directive} { printClass("directive", yytext); }

.|\n    { ECHO; }

%%

/*
make ex-5-3 && ./ex-5-3 lex.yy.c teste.html
*/
int main(int argc, char *argv[])
{
    /* check command line arguments */
    switch (argc)
    {
        case 1: // read from stdin, write to stdout
        {
            break;
        }
        case 2: // read from given file, write to stdout
        {
            if ((yyin = fopen(argv[1], "r")) == NULL)
            {
                fprintf(stderr, "Fail openning input file \"%s\"\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            break;
        }
        case 3: // read from given file, write to given file
        {
            if ((yyin = fopen(argv[1], "r")) == NULL)
            {
                fprintf(stderr, "Fail openning input file \"%s\"\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            if ((yyout = fopen(argv[2], "w")) == NULL)
            {
                fprintf(stderr, "Fail openning output file \"%s\"\n", argv[2]);
                exit(EXIT_FAILURE);
            }
            break;
        }
        default:
        {
            fprintf(stderr, "Wrong number of arguments\n");
            exit(EXIT_FAILURE);
        }
    }

    /* start HTML document */
    fprintf(yyout, 
        "<!DOCTYPE html>\n"
        "<html>\n"
            "\t<head>\n"
            "\t<style>\n"
				"\t\tspan {font-size:large;}\n"
                "\t\tspan.keyword {color:#f92772;}\n"
                "\t\tspan.number {color:yellow;}\n"
                "\t\tspan.var_names {color:orange;}\n"
                "\t\tspan.normal {color:white;}\n"
                "\t\tspan.directive {color:#f9276f;}\n"
                "\t\tspan.comments {color:#75715e;}\n"
                "\t\tspan.type_values {color:#66d9ef;}\n"
                "\t\tspan.constant {color:yellow;}\n"
                "\t\tspan.string {color:grey;}\n"
            "\t</style>\n"
        "</head>\n"
        "\n"
        "<body style=\"background-color: #272822\">\n"
        "<pre>\n");

    /* process BODY */
    yylex();

    /* end HTML document */
    fprintf(yyout,
        "</pre>\n"
        "</body>\n");

    /* that's all */
    return 0;
}

