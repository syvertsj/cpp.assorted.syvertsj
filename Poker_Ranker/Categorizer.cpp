/**
 * Categorizer.cpp
 *
 *      Author: syvertsj
 */

#include "Categorizer.hpp"
#include <iostream>

namespace poker {

Categorizer::Categorizer()
{
	// TODO Auto-generated constructor stub
	//std::cout << " - categorizer created - " << std::endl;
}

Categorizer::~Categorizer()
{
	// TODO Auto-generated destructor stub
}

// scan hand for matching values of card, excluding itself
int Categorizer::scanForMatch(Hand hand, Card card, int index)
{
	int count = 0;

	for (int i = 0; i < Hand::NUMCARDS; i++)
	{
		if(i != index)
		{
			if( card.getRank() == hand.getCard(i).getRank() )
			{
				count++;
			}
		}
	}

	return count;
}


} // namespace 'poker'

