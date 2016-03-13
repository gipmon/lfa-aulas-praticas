#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "M.h"

int main(int argc, char* argv[])
{
    /* check number of arguments */
    if (argc == 1)
    {
		fprintf(stderr, "Número de argumentos errado\n"
			"%s palavra ...\n", argv[0]);
		return EXIT_FAILURE;
	}

    int i;
    for (i=1; i<argc; i++)
    {
        /* check if word is valid */
        if (strspn(argv[i], alphabet) != strlen(argv[i]))
        {
            printf("\"%s\" contains invalid characters\n", argv[i]);
            continue;
        }

        /* check if word belongs to the language */
        if (M(argv[i]))
        {
            printf("\"%s\" belongs to L\n", argv[i]);
        }
        else
        {
            printf("\"%s\" does not belong to L\n", argv[i]);
        }
    }
    return 0;
}

