#include <stdbool.h>
#include <string.h>

/* number of symbols in input alphabet */
#define NInputSymbols 3

const char* inputAlphabet = "abc";

/* a way to get the ord of a symbol */
static int ordOf(char c)
{
    char* p = strchr((char*)inputAlphabet, c);
    return (p==NULL) ? -1 : p - inputAlphabet;
}

/* number of states */
#define NStates 4

/* define state names */
enum { A, B, C, AB };

/* the initial state */
#define initialState C

/* the transition table */
static const int delta[NStates][NInputSymbols] =
{
      /*      'a'  'b'  'c'  */
    { /* A */  A,   AB,  C  },
    { /* B */  A,   B,   C  },
    { /* C */  A,   B,   C  },
    { /* AB */ A,   B,   C  }
};

/* the transition table */
static const char gamma[NStates][NInputSymbols] =
{
      /*       'a'    'b'    'c'  */
    { /* A */  '4',   '4',   '3'  },
    { /* B */  '1',   '5',   '3'  },
    { /* C */  '1',   '2',   '3'  },
    { /* AB */ '1',   '5',   '6'  }
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

