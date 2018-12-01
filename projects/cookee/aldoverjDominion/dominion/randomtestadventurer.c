/************************************************************
Author: Emmet Cooke
Description: 
Makefile addition:
************************************************************/
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
    int numPlayers = 0, currentPlayer = 0, seed = 0, testScore = 0;
    int drawnTreasure = 0, z = 0;
    int tempHand[MAX_HAND];

    int i;
    for (i = 0; i < 1000; i++)
    {
    	testScore = 0;
    	numPlayers = rand() % MAX_PLAYERS + 1;
    	seed = rand() % 1000 + 1;
    	initializeGame(numPlayers, k, seed, &G);
    	memcpy(&testG, &G, sizeof(struct gameState));

    	currentPlayer = rand() % MAX_PLAYERS + 1;

    	testG.hand[currentPlayer][0] = adventurer;

    	cardEffect(adventurer, -1, -1, -1, &testG, 0, 0);
    	// playAdventurer below segments, whereas cardEffect above does not.
    	//playAdventurer(currentPlayer, &testG, tempHand, drawnTreasure, z);
    	//printf("Test G\n---\nnumActions: %d\nhandCount: %d\ndiscardCount: %d\nplayedCardsCount: %d\n", 
    	//	testG.numActions, testG.handCount[currentPlayer], testG.discardCount[currentPlayer], testG.playedCardCount);

    	//printf("G\n---\nnumActions: %d\nhandCount: %d\ndiscardCount: %d\nplayedCardsCount: %d\n", 
    	//	G.numActions, G.handCount[currentPlayer], G.discardCount[currentPlayer], G.playedCardCount);

    	if (testG.playedCardCount > G.playedCardCount)
    	{
    		printf("Card successfully played!\n");
    		testScore++;
    	}
    	else
    	{
    		printf("Card unsuccessful!\n");
    	}

    	if (testG.handCount[currentPlayer] == (G.handCount[currentPlayer] + 2))
    	{
    		printf("Card successfully added!\n");
    		testScore++;
    	}
    	else
    	{
    		printf("Cards unsuccessfully added!\n");
    	}

    	printf("Test %d\n----------------------\n", i);
	    switch (testScore)
	    {
	    	case 0:
	    		printf("Adventurer passed 0/2!\n");
	    		break;
	    	case 1:
	    		printf("Adventurer passed 1/2!\n");
	    		break;
	    	default:
	    		printf("Adventurer passed 2/2!\n");
	    		break;
	    }
	    printf("\n\n");
    }
	return 0;
}