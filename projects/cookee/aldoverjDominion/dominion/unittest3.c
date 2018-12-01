/************************************************************
File: unittest3.c
Author: Emmet Cooke
Description: Unit test for the getCost in dominion.

Makefile addition:
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
************************************************************/
//test getCost
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

    int card1, card2, card3, card4, card5;
    card1 = k[0];
    card2 = k[1];
    card3 = k[2];
    card4 = k[3];
    card5 = k[4];

    printf("\nTesting getCost:\n\n");
    // test adventurer cost
    if (getCost(card1) == 6)
    {
        printf("Adventurer cost correct!\n");
        testScore++;
    }
    else
    {
        printf("Adventurer cost incorrect!\n");
    }

    // test gardens cost
    if (getCost(card2) == 4)
    {
        printf("Gardens cost correct!\n");
        testScore++;
    }
    else
    {
        printf("Gardens cost incorrect!\n");
    }

    // test embargo cost
    if (getCost(card3) == 2)
    {
        printf("Embargo cost correct!\n");
        testScore++;
    }
    else
    {
        printf("Embargo cost incorrect!\n");
    }

    // test village cost
    if (getCost(card4) == 3)
    {
        printf("Village cost correct!\n");
        testScore++;
    }
    else
    {
        printf("Village cost incorrect!\n");
    }

    // test minion cost
    if (getCost(card5) == 5)
    {
        printf("Minion cost correct!\n");
        testScore++;
    }
    else
    {
        printf("Minion cost incorrect!\n");
    }

    // Show if test is successful
    if (testScore == 5)
    {
        printf("getCost test successful!\n");
    }
    else
    {
        printf("getCost test failed!\n");
    }
	return 0;
}