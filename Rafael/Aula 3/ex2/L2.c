#include <stdbool.h>
#include <string.h>

#include "M.h"

/* number of symbols in alphabet */
#define NSymbols 3

const char* alphabet = "abc";

/* a way to get the ord of a symbol */
#define ordOf(a)(a-'a')

/* number of states */
#define NStates 5

/* define state names */
enum {A, B, C, D, E};

/* the transition table */
static const int delta[NStates][NSymbols] =
{
      /*       'a'  'b'  'c'  */
    { /* A */   B,   A,   A },
    { /* B */   B,   C,   A },
    { /* C */   D,   C,   C },
    { /* D */   D,   E,   C },
    { /* E */   E,   E,   E },
};

/* the initial state */
static const int initialState = A;

/* the number of accept states */
#define NAcceptStates 1

/* the set of accept states */
static const int acceptSet[NAcceptStates] =
{
    E
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

