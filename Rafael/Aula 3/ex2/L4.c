#include <stdbool.h>
#include <string.h>

#include "M.h"

/* number of symbols in alphabet */
#define NSymbols 3

const char* alphabet = "abc";

/* a way to get the ord of a symbol */
#define ordOf(a)(a-'a')

/* number of states */
#define NStates 4

/* define state names */
enum {A, B, C, D};

/* the transition table */
static const int delta[NStates][NSymbols] =
{
      /*       'a'  'b'  'c'  */
    { /* A */   C,   B,   A },
    { /* B */   D,   B,   B },
    { /* C */   A,   D,   C },
    { /* D */   B,   D,   D },
};

/* the initial state */
static const int initialState = A;

/* the number of accept states */
#define NAcceptStates 3

/* the set of accept states */
static const int acceptSet[NAcceptStates] =
{
    A, B, C
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