/*
 * OnePairCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "OnePairCategorizer.hpp"

namespace poker 
{

OnePairCategorizer::OnePairCategorizer() 
{
	// TODO Auto-generated constructor stub
}

OnePairCategorizer::~OnePairCategorizer() 
{
	// TODO Auto-generated destructor stub
}

// two cards of same value
// note: this will assume higher categories have been evaluated and failed
bool OnePairCategorizer::doCategorize(Hand hand)
{
	//cout << "OnePairCategorizer::doCategorize" << endl;

	bool onePair  = false;
	int  match    = 0;
	int  maxMatch = 0;
	
	// find possible matches for each card and determine maximum
	for (int i = 0; i < Hand::NUMCARDS; i++)
	{
		match = this->scanForMatch(hand, hand.getCard(i), i);

		if (match > maxMatch)
		{
			maxMatch = match;
		}
	}

	if (1 == maxMatch)
	{
		hand.setCategory(Hand::ONEPAIR);
		onePair = true;	
	}

	return onePair;
}

} // namespace 'poker'
