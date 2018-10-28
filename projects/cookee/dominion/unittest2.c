/************************************************************
File: unittest2.c
Author: Emmet Cooke
Description: Unit test for the whoseTurn in dominion.

Makefile addition:
unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
************************************************************/
//test whoseTurn
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct gameState G, testG;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 10, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    int testScore = 0;

    printf("\nTesting whoseTurn:\n\n");
    if (whoseTurn(&testG) == 0)
    {
        printf("First player turn is correct!\n");
        testScore++;
    }
    else
    {
        printf("First player turn is incorrect!\n");
    }

    endTurn(&testG);

    if (whoseTurn(&testG) == 0)
    {
        printf("Second player turn is incorrect!\n");
    }
    else
    {
        printf("Second player turn is correct!\n");
        testScore++;
    }

    // Show if test is successful
    if (testScore == 2)
    {
        printf("whoseTurn test successful!\n");
    }
    else
    {
        printf("whoseTurn test failed!\n");
    }
	return 0;
}