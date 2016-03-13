#include <stdbool.h>
#include <string.h>

/* number of symbols in input alphabet */
#define NInputSymbols 2

const char* inputAlphabet = "ed";

/* a way to get the ord of a symbol */
static int ordOf(char c)
{
    char* p = strchr((char*)inputAlphabet, c);
    return (p==NULL) ? -1 : p - inputAlphabet;
}

/* number of states */
#define NStates 8

/* define state names */
enum { DDD, EDD, DEE /*...*/ };

/* the initial state */
#define initialState DDD

/* the transition table */
static const int delta[NStates][NInputSymbols] =
{
      /*         'A'    'B'  */
    { /* DDD */  DDD,   DDD  },
    { /* DDD */  DDD,   DDD  },
    { /* DDD */  DDD,   DDD  },
    { /* DDD */  DDD,   DDD  },
    { /* DDD */  DDD,   DDD  },
    { /* DDD */  DDD,   DDD  },
    { /* DDD */  DDD,   DDD  },
    { /* DDD */  DDD,   DDD  }
};

/* the transition table */
static const char gamma[NStates][NInputSymbols] =
{
      /*         'A'    'B'  */
    { /* DDD */  '0',   '0' },
    { /* DDD */  '0',   '0' },
    { /* DDD */  '0',   '0' },
    { /* DDD */  '0',   '0' },
    { /* DDD */  '0',   '0' },
    { /* DDD */  '0',   '0' },
    { /* DDD */  '0',   '0' },
    { /* DDD */  '0',   '0' }
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

