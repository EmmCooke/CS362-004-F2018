/************************************************************
Author: Emmet Cooke
Description: Card test for the smithy card in dominion.

Makefile addition:
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
************************************************************/
//test smithy
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
    int handPos = 0;

    initializeGame(2, k, 10, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = whoseTurn(&G);
    int testScore = 0;

    printf("Testing Smithy:\n");
    playSmithy(currentPlayer, &testG, handPos);
    // test 1
    // If testG is 1 greater than G, smithy was played
    if (testG.playedCardCount == (G.playedCardCount + 1))
    {
    	printf("Card successfully played!\n");
    	testScore++;
    }
    else
    {
    	printf("Card unsuccessful!\n");
    }

    // test 2
    // testG should have 2 additional cards as smithy has been discarded
    if (testG.handCount[currentPlayer] == (G.handCount[currentPlayer] + 2))
    {
    	printf("Cards successfully added!\n");
    	testScore++;
    }
    else
    {
    	printf("Card unsuccessful!\n");	
    }

    // Show if test is successful
    if (testScore == 2)
    {
    	printf("\nSmithy test successful!\n");
    }
    else
    {
    	printf("\nSmithy test failed!\n");
    }
	return 0;
}