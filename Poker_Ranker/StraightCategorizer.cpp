/*
 * StraightCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "StraightCategorizer.hpp"

namespace poker 
{

StraightCategorizer::StraightCategorizer() 
{
	// TODO Auto-generated constructor stub

}

StraightCategorizer::~StraightCategorizer() 
{
	// TODO Auto-generated destructor stub
}

// check for rank descending by one per successive  card
// note: hand must be sorted for algorithm to work
bool StraightCategorizer::doCategorize(Hand hand)
{
	//cout << "StraightCategorizer::doCategorize" << endl;

	bool straight = true;
	
	for (int i = 0; i < Hand::NUMCARDS-1; i++)
	{
		if ( hand.getCard(i).getRank() != hand.getCard(i+1).getRank()+1 )
		{
			straight = false;
			break;
		}
	}

	if (straight)
	{
		hand.setCategory(Hand::STRAIGHT);
	}

	return straight;
}

} // namespace 'poker'
