/************************************************************
Author: Emmet Cooke
Description: Card test for the council room card in dominion.

Makefile addition:
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
************************************************************/
//test council room
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

    printf("Testing Council Room:\n");
    playCouncilRoom(currentPlayer, &testG, handPos);
    // test 1
    // If testG is greater than G, councilRoom was played
    if (testG.playedCardCount > G.playedCardCount)
    {
    	printf("Card successfully played!\n");
    	testScore++;
    }
    else
    {
    	printf("Card unsuccessful!\n");
    }

    // test 2
    // test player should have 1 more buy
    if (testG.numBuys == (G.numBuys + 1))
    {
    	printf("Number of buys successfully increased!\n");
    	testScore++;
    }
    else
    {
    	printf("Number of buys not increased!\n");
    }

    // test 3
    // Check the handcount
    if (testG.handCount[currentPlayer] == (G.handCount[currentPlayer] + 2))
    {
    	printf("Cards successfully added!\n");
    	testScore++;
    }
    else
    {
    	printf("Cards unsuccessful added!\n");	
    }

    // Show if test is successful
    if (testScore == 3)
    {
    	printf("\nCouncil Room test successful!\n");
    }
    else
    {
    	printf("\nCouncil Room test failed!\n");
    }
	return 0;
}