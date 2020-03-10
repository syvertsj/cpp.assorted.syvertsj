/*
 * FullHouseCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "FullHouseCategorizer.hpp"

namespace poker 
{

FullHouseCategorizer::FullHouseCategorizer() 
{
	// TODO Auto-generated constructor stub
}

FullHouseCategorizer::~FullHouseCategorizer() 
{
	// TODO Auto-generated destructor stub
}

bool FullHouseCategorizer::doCategorize(Hand hand)
{
	//cout << "FullHouseCategorizer::doCategorize" << endl;

	bool fullHouse = false;
	int  match     = 0;
	int  maxMatch  = 0;
	int  count1    = 0;
	int  count2    = 0;

	// try to determine separate sets: (1) two matches and (2) one match
	for (int i = 0; i < Hand::NUMCARDS; i++)
	{
		match = this->scanForMatch(hand, hand.getCard(i), i);

		if (match > maxMatch)
		{
			maxMatch = match;
		}
		if (maxMatch == 1)
		{
			count1++;
		}
		if (maxMatch == 2)
		{
			count2++;
		}
	}

	if (count1 == 1 && count2 == 2)
	{
		hand.setCategory(Hand::FULLHOUSE);
		fullHouse = true;	
	}

	return fullHouse;
}

} // namespace 'poker'
