/************************************************************
File: unittest4.c
Author: Emmet Cooke
Description: Unit test for the scoreFor in dominion.

Makefile addition:
unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
************************************************************/
//test scoreFor
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

    printf("\nTesting scoreFor:\n\n");
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("Player %d Score: %d\n", (i + 1), scoreFor(i, &testG));
        testScore++;
    }

    // Show if test is successful
    if (testScore == 2)
    {
        printf("scoreFor test successful!\n");
    }
    else
    {
        printf("scoreFor test failed!\n");
    }
	return 0;
}