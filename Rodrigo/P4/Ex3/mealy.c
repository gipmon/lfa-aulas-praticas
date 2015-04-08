/* https://github.com/gipmon/lfa-aulas-praticas */
#include <stdbool.h>
#include <string.h>

/* number of symbols in input alphabet */
#define NInputSymbols 3

const char* inputAlphabet = "ecd";

/* a way to get the ord of a symbol */
static int ordOf(char c)
{
    char* p = strchr((char*)inputAlphabet, c);
    return (p==NULL) ? -1 : p - inputAlphabet;
}

/* number of states */
#define NStates 8

/* define state names */
enum { DDD, EDD, DDE, EED, DED, EDE, EEE, DEE };

/* the initial state */
#define initialState DDD

/* the transition table */
static const int delta[NStates][NInputSymbols] =
{
      /*         'e'    'c'    'd'  */
    { /* DDD */  EDD,   EED,   DDE  },
    { /* EDD */  DDD,   DED,   EDE  },
    { /* DDE */  EDE,   EEE,   DDD  },
    { /* EED */  DED,   EDE,   EEE  },
    { /* DED */  EED,   DDE,   DEE  },
    { /* EDE */  DDE,   DEE,   EDD  },
    { /* EEE */  DEE,   EDD,   EED  },
    { /* DEE */  EEE,   DDD,   DED  }
};

/* the transition table */
static const char gamma[NStates][NInputSymbols] =
{
      /*         'e'    'c'    'd'  */
    { /* DDD */  'E',   'E',   'C' },
    { /* DDD */  'C',   'C',   'C' },
    { /* DDD */  'E',   'E',   'D' },
    { /* DDD */  'C',   'C',   'C' },
    { /* DDD */  'E',   'C',   'E' },
    { /* DDD */  'C',   'C',   'D' },
    { /* DDD */  'C',   'D',   'D' },
    { /* DDD */  'E',   'D',   'D' }
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
