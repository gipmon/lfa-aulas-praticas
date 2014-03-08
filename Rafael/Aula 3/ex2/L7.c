#include <stdbool.h>
#include <string.h>

#include "M.h"

/* number of symbols in alphabet */
#define NSymbols 3

const char* alphabet = "abc";

/* a way to get the ord of a symbol */
#define ordOf(a)(a-'a')

/* number of states */
#define NStates 10

/* define state names */
enum {A, B, C, D, E, F, G, H, I, J};

/* the transition table */
static const int delta[NStates][NSymbols] =
{
      /*       'a'  'b'  'c'  */
    { /* A */   B,   A,   A },
    { /* B */   B,   C,   A },
    { /* C */   D,   A,   A },
    { /* D */   D,   F,   E },
    { /* E */   D,   E,   E },
    { /* F */   G,   E,   E },
    { /* G */   G,   F,   H },
    { /* H */   G,   H,   H },
    { /* I */   J,   I,   I },
    { /* J */   J,   J,   J },
};

/* the initial state */
static const int initialState = A;

/* the number of accept states */
#define NAcceptStates 9

/* the set of accept states */
static const int acceptSet[NAcceptStates] =
{
    A, B, C, D, E, F, G, H, I
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