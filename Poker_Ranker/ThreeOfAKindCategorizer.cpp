/*
 * ThreeOfAKindCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "ThreeOfAKindCategorizer.hpp"

namespace poker 
{

ThreeOfAKindCategorizer::ThreeOfAKindCategorizer() 
{
	// TODO Auto-generated constructor stub
}

ThreeOfAKindCategorizer::~ThreeOfAKindCategorizer() 
{
	// TODO Auto-generated destructor stub
}

// three cards of same value
bool ThreeOfAKindCategorizer::doCategorize(Hand hand)
{
	//cout << "ThreeOfAKindCategorizer::doCategorize" << endl;

	bool threeOfAKind = false;
	int  match        = 0;
	int  maxMatch     = 0;
	
	// find possible matches for each card and determine maximum
	for (int i = 0; i < Hand::NUMCARDS; i++)
	{
		match = this->scanForMatch(hand, hand.getCard(i), i);

		if (match > maxMatch)
		{
			maxMatch = match;
		}
	}
	
	if (2 == maxMatch)
	{
		hand.setCategory(Hand::THREEOFAKIND);
		threeOfAKind = true;	
	}

	return threeOfAKind;
}

} // namespace 'poker'
