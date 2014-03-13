#include <stdbool.h>
#include <string.h>

#include "M.h"

/* number of symbols in alphabet */
#define NSymbols 3

const char* alphabet = "abc";

/* a way to get the ord of a symbol */
#define ordOf(a)    (a-'a')

/* number of states */
#define NStates 8

/* define state names */
enum { A, B, C, D, E, F, G, H};

/* the transition table */
static const int delta[NStates][NSymbols] =
{
      /*       'a'  'b'  'c'  */
    { /* A */   B,   E,   G },
    { /* B */   C,   E,   G },
    { /* C */   D,   E,   G },
    { /* D */   D,   D,   D },
    { /* E */   B,   F,   G },
    { /* F */   B,   D,   G },
    { /* G */   B,   E,   H },
    { /* H */   B,   E,   D }
};

/* the initial state */
static const int initialState = A;

/* the number of accept states */
#define NAcceptStates 1

/* the set of accept states */
static const int acceptSet[NAcceptStates] = 
{ 
    D 
};

bool M(const char* u)
{
    int i;
    int state = initialState; // the current state, initialized */
    for (i=0; i<strlen(u); i++)
    {
        state = delta[state][ordOf(u[i])];
    }

    for (i=0; i<NAcceptStates; i++)
    {
        if (state == acceptSet[i]) return true;
    }
    return false;
}

