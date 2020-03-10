/*
 * TwoPairCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "TwoPairCategorizer.hpp"

namespace poker 
{

TwoPairCategorizer::TwoPairCategorizer() 
{
	// TODO Auto-generated constructor stub
}

TwoPairCategorizer::~TwoPairCategorizer() 
{
	// TODO Auto-generated destructor stub
}

// 2 of two cards of same value
bool TwoPairCategorizer::doCategorize(Hand hand)
{
	//cout << "TwoPairCategorizer::doCategorize" << endl;

	bool twoPair   = false;
	int  match     = 0;
	int  maxMatch  = 0;
	int  countPair = 0;
	
	// find possible matches for each card and determine maximum
	for (int i = 0; i < Hand::NUMCARDS; i++)
	{
		match = this->scanForMatch(hand, hand.getCard(i), i);

		if (match > maxMatch)
		{
			maxMatch = match;
			countPair++;
		}
	}
	
	if (2 == countPair)
	{
		hand.setCategory(Hand::TWOPAIR);
		twoPair = true;	
	}

	return twoPair;
}

} // namespace 'poker'
