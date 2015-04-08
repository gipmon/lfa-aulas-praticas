/* https://github.com/gipmon/lfa-aulas-praticas */
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
enum { DDD, EDD, DEE, EEE, DED, DDE, EED, EDE };

/* the initial state */
#define initialState DDD

/* the transition table */
static const int delta[NStates][NInputSymbols] =
{
      /*         'e'    'e'  */
    { /* DDD */  EDD,   DEE  },
    { /* EDD */  DED,   EEE  },
    { /* DEE */  EEE,   DED  },
    { /* EEE */  DDE,   EED  },
    { /* DED */  EED,   DDE  },
    { /* DDE */  EDE,   DDD  },
    { /* EED */  DDD,   EDE  },
    { /* EDE */  DEE,   EDD  }
};

/* the transition table */
static const char gamma[NStates][NInputSymbols] =
{
      /*         'e'    'd'  */
    { /* DDD */  'E',   'E' },
    { /* EDD */  'E',   'E' },
    { /* DEE */  'E',   'D' },
    { /* EEE */  'D',   'D' },
    { /* DED */  'E',   'D' },
    { /* DDE */  'E',   'D' },
    { /* EED */  'D',   'D' },
    { /* EDE */  'E',   'D' }
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
