/**
 * mainPokerRanker.cpp
 *
 *      Author: syvertsj
 */

#include "PokerRanker.hpp"

#include <iostream>
#include <stdlib.h>

using namespace poker;
using namespace std;

int main(int argc, char* argv[])
{
	int option = 0;

	cout << " Poker Ranker Main " << endl;

	// select parser options:
	do {
		cout << " select dealer: " << endl;
		cout << "       1) libconfig" << endl;
		cout << "       2) standard plain text" << endl;
		cin >> option;
		if (option != dealer::LIBCONFIG && option != dealer::STANDARD) 
		{
			cout << " select either option 1 or 2" << endl;
		}
	} while (option != dealer::LIBCONFIG && option != dealer::STANDARD);

	// instantiate poker ranker object and hand things off:
	PokerRanker pokerRanker;

	std::cout << " < PokerRanker object created > " << std::endl;

	pokerRanker.useDealer(option);

	return EXIT_SUCCESS;
}
