/************************************************************
Author: Emmet Cooke
Description: Card test for the adventurer card in dominion.

Makefile addition:
cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
************************************************************/

//test adventurer
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
    int drawnTreasure = 0, z = 0;
    int tempHand[MAX_HAND];

    initializeGame(2, k, 10, &G);
    memcpy(&testG, &G, sizeof(struct gameState));
    int currentPlayer = whoseTurn(&G);
    int testScore = 0;

    printf("Testing Adventurer:\n");
    playAdventurer(currentPlayer, &testG, tempHand, drawnTreasure, z);
    // test 1
    // Is card played
    if (testG.playedCardCount > G.playedCardCount)
    {
    	printf("Card successfully played!\n");
    	testScore++;
    }
    else
    {
    	printf("Card not succesfully played!\n");
    }

    // test 3
    // Check the handcount. Should be 2 greater.
    if (testG.handCount[currentPlayer] == (G.handCount[currentPlayer] + 2))
    {
    	printf("Cards successfully added!\n");
    	testScore++;
    }
    else
    {
    	printf("Cards unsuccessfully added!\n");
    }

    // Show if test is successful
    if (testScore == 2)
    {
    	printf("\nAdventurer test successful!\n");
    }
    else
    {
    	printf("\nAdventurer test failed!\n");
    }
	return 0;
}