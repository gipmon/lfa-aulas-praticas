/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "mealy.h"

int main(int argc, char* argv[])
{
    int i;
    for (i=1; i<argc; i++)
    {
        int n = strlen(argv[i]);

        /* check if word is valid */
        if (strspn(argv[i], inputAlphabet) != n)
        {
            printf("\"%s\" contains invalid characters\n", argv[i]);
            continue;
        }

        /* computes the response */
        char v[n+1];
        mealy(argv[i], v);
        printf("\"%s\" --> \"%s\"\n", argv[i], v);
    }
    return 0;
}
