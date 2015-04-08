/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdbool.h>
#include <string.h>

/* number of symbols in input alphabet */
#define NInputSymbols 4

const char* inputAlphabet = "0123";

/* a way to get the ord of a symbol */
static int ordOf(char c)
{
    char* p = strchr((char*)inputAlphabet, c);
    return (p==NULL) ? -1 : p - inputAlphabet;
}

/* number of states */
#define NStates 3

/* define state names */
enum { A, B, C };

/* the initial state */
#define initialState A

/* the transition table */
static const int delta[NStates][NInputSymbols] =
{
      /*         '0'  '1'  '2'  '3'  */
    { /* A(0) */  A,   B,   C,   A  },
    { /* B(1) */  B,   C,   A,   B  },
    { /* C(2) */  C,   A,   B,   C  }
};

/* the transition table */
static const char gamma[NStates][NInputSymbols] =
{
      /*         '0'  '1'  '2'  '3'  */
    { /* A(0) */  '0',   '1',   '2',   '0'  },
    { /* B(1) */  '1',   '2',   '0',   '1'  },
    { /* C(2) */  '2',   '0',   '1',   '2'  }
};

void mealy(const char* u, char* v)
{
    int i;
    int state = initialState; // the current state, initialized */
    for (i=0; i<strlen(u); i++)
    {
		v[i] = gamma[state][ordOf(u[i])];
        state = delta[state][ordOf(u[i])];
    }

	v[i] = '\0';
}
