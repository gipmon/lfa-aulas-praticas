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
enum { DDD, EDD, EED, DED, EDE, DDE, DEE, EEE };

/* the initial state */
#define initialState DDD

/* the transition table */
static const int delta[NStates][NInputSymbols] =
{
      /*         'e'    'd'  */
    { /* DDD */  EDD,   EED  },
    { /* EDD */  DDD,   DED  },
    { /* EED */  DED,   EDE  },
    { /* DED */  EED,   DDE  },
    { /* EDE */  DDE,   DEE  },
    { /* DDE */  EDE,   EEE  },
    { /* DEE */  EEE,   DDD  },
    { /* EEE */  DEE,   DDD  }
};

/* the transition table */
static const char gamma[NStates][NInputSymbols] =
{
      /*         'e'    'd'  */
    { /* DDD */  'E',   'E' },
    { /* EDD */  'C',   'C' },
    { /* EED */  'C',   'C' },
    { /* DED */  'E',   'C' },
    { /* EDE */  'C',   'C' },
    { /* DDE */  'E',   'E' },
    { /* DEE */  'E',   'D' },
    { /* EEE */  'C',   'D' }
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

