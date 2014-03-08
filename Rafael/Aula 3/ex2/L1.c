#include <stdbool.h>
#include <string.h>

#include "M.h"

/* number of symbols in alphabet */
#define NSymbols 3

const char* alphabet = "abc";

/* a way to get the ord of a symbol */
#define ordOf(a)(a-'a')

/* number of states */
#define NStates 8

/* define state names */
enum {A, B, C, D, E, F, G, H};

/* the transition table */
static const int delta[NStates][NSymbols] =
{
      /*       'a'  'b'  'c'  */
    { /* A */   B,   D,   F },
    { /* B */   C,   D,   F },
    { /* C */   H,   D,   F },
    { /* D */   B,   E,   F },
    { /* E */   B,   H,   F },
    { /* F */   B,   D,   G },
    { /* G */   B,   D,   H },
    { /* H */   H,   H,   H },
};

/* the initial state */
static const int initialState = A;

/* the number of accept states */
#define NAcceptStates 1

/* the set of accept states */
static const int acceptSet[NAcceptStates] =
{
    H
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

