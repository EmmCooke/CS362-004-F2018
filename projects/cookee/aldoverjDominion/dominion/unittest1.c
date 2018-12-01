/************************************************************
File: unittest1.c
Author: Emmet Cooke
Description: Unit test for the numHandCards in dominion.

Makefile addition:
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
************************************************************/
//test numHandCards
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

    printf("\nTesting numHandCards:\n\n");
    // test 1
    //printf("%d\n", numHandCards(&testG));
    if (numHandCards(&testG) == 5)
    {
        printf("Number of cards in hand correct!\n");
        testScore++;
    }
    else
    {
        printf("Number of cards in hand incorrect!\n");
    }

    // Show if test is successful
    if (testScore == 1)
    {
        printf("numHandCards test successful!\n");
    }
    else
    {
        printf("numHandCards test failed!\n");
    }
	return 0;
}