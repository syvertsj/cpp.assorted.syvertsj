/*
 * FlushCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "FlushCategorizer.hpp"

namespace poker 
{

FlushCategorizer::FlushCategorizer() 
{
	// TODO Auto-generated constructor stub

}

FlushCategorizer::~FlushCategorizer() 
{
	// TODO Auto-generated destructor stub
}

// compare suit of first card to the rest
// if any are different, hand is not a flush
bool FlushCategorizer::doCategorize(Hand hand)
{
	//cout << "FlushCategorizer::doCategorize" << endl;

	bool flush = false;

	int i = 1;
	do 
	{
		if ( hand.getCard(i-1).getSuit() == hand.getCard(i).getSuit() )
		{
			flush = true;
		} 
		else 
		{
			flush = false;
		}
	} while ( (++i < Hand::NUMCARDS) && flush );
	
	return flush;	
}

} // namespace 'poker'
