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
    
    // test cardEffect - smithy
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

		testG.hand[currentPlayer][0] = smithy;
    	// Check if player has card

		cardEffect(smithy, -1, -1, -1, &testG, 0, 0);

		// check that smithy was played
		if (testG.playedCardCount == (G.playedCardCount + 1))
		{
			//printf("Card successfully played!\n");
			testScore++;
		}
		// else
		// {
		// 	printf("Card unsuccessful!\n");
		// }

		//printf("testG: %d G: %d\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]);
		// check that at least 3 cards were discarded 
		if (testG.discardCount[currentPlayer] > (G.discardCount[currentPlayer] + 3))
		{
			//printf("\nSmithy test successful!\n");
			testScore++;
		}
		// else
		// {
		// 	printf("\nSmithy test failed!\n");
		// }

		printf("Test %d\n------------------\n", i);
	    switch (testScore)
	    {
	    	case 0:
	    		printf("Smithy passed 0/2!\n");
	    		break;
	    	case 1:
	    		printf("Smithy passed 1/2!\n");
	    		break;
	    	default:
	    		printf("Smithy passed 2/2!\n");
	    		break;
	    }
	    printf("\n\n");
    }
	return 0;
}