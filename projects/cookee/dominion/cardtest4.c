/************************************************************
Author: Emmet Cooke
Description: Card test for the village card in dominion.

Makefile addition:
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
************************************************************/
//test village
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

    printf("Testing Village:\n");
    playVillage(currentPlayer, &testG, handPos);
    // test 1
    // If testG is 1 greater than G, village was played
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
    // testG should be equal as village has been discarded
    if (testG.handCount[currentPlayer] == G.handCount[currentPlayer])
    {
    	printf("Cards successfully added!\n");
    	testScore++;
    }
    else
    {
    	printf("Card unsuccessful!\n");	
    }

    // test 3
    // testG should have 2 additional actions over G
    if (testG.numActions == (G.numActions + 2))
    {
    	printf("Actions successfully added!\n");
    	testScore++;
    }
    else
    {
    	printf("Actions unsuccessfully added!\n");
    }

    // Show if test is successful
    if (testScore == 3)
    {
    	printf("\nVillage test successful!\n");
    }
    else
    {
    	printf("\nVillage test failed!\n");
    }
	return 0;
}