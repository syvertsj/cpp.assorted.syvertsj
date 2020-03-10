/*
 * FourOfAKindCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "FourOfAKindCategorizer.hpp"

namespace poker 
{

FourOfAKindCategorizer::FourOfAKindCategorizer() 
{
	// TODO Auto-generated constructor stub

}

FourOfAKindCategorizer::~FourOfAKindCategorizer() 
{
	// TODO Auto-generated destructor stub
}

bool FourOfAKindCategorizer::doCategorize(Hand hand)
{
	//cout << "FourOfAKindCategorizer::doCategorize" << endl;

	bool fourOfAKind  = false;
	int  match        = 0;
	int  maxMatch     = 0;

	for (int i = 0; i < Hand::NUMCARDS; i++)
	{
		match = this->scanForMatch(hand, hand.getCard(i), i);

		if (match > maxMatch)
		{
			maxMatch = match;
		}
	}

	if (3 == maxMatch)
	{
		hand.setCategory(Hand::FOUROFAKIND);
		fourOfAKind = true;	
	}

	return fourOfAKind;
}

} // namespace 'poker'
