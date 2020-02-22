#include <iostream>
#include "Poker.h"


using namespace std;



int main()
{



	Hand player;
	Deck game1;
	game1.CardsToHand(player);
	cout << player.getCards()[0].seniority << player.getCards()[1].suit;



	return 0;
}