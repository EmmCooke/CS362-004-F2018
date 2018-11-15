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

    // test cardEffect - village
    // randomize the variables for cardEffect
    int i;
    // Do 1000 tests
    for (i = 0; i < 1000; i++)
    {
    	testScore = 0;
    	numPlayers = rand() % MAX_PLAYERS + 1;
    	seed = rand() % 1000 + 1;
    	initializeGame(numPlayers, k, seed, &G);
    	memcpy(&testG, &G, sizeof(struct gameState));

    	currentPlayer = rand() % MAX_PLAYERS + 1;

    	// Make sure the player has the village card to test
    	testG.hand[currentPlayer][0] = village;

    	// Play the village card
    	cardEffect(village, -1, -1, -1, &testG, 0, 0);

    	// If the player in testG has played the card
    	if (testG.playedCardCount == (G.playedCardCount + 1))
		{
			//printf("Card successfully played!\n");
			testScore++;
		}
		// else
		// {
		// 	printf("Card unsuccessful!\n");
		// }

		// check that additional actions were added
		if (testG.numActions == (G.numActions + 2))
		{
			//printf("\nVillage test successful!\n");
			testScore++;
		}
		// else
		// {
		// 	printf("\nVillage test failed!\n");
		// }

		// If both tests passed, it will return successful
		// if (testScore == 2)
		// {
		// 	printf("\nVillage test successful!\n");
		// }
	 //    else
	 //    {
	 //    	printf("\nVillage test failed!\n");
	 //    }

	    printf("Test %d\n-------------------\n", i);
	    switch (testScore)
	    {
	    	case 0:
	    		printf("Village passed 0/2!\n");
	    		break;
	    	case 1:
	    		printf("Village passed 1/2!\n");
	    		break;
	    	default:
	    		printf("Village passed 2/2!\n");
	    		break;
	    }
	    printf("\n\n");
    }
	return 0;
}