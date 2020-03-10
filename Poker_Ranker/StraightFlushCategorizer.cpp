/*
 * StraightFlushCategorizer.cpp
 *
 *      Author: syvertsj
 */

#include "StraightFlushCategorizer.hpp"
//#include "StraightCategorizer.hpp"
//#include "FlushCategorizer.hpp" 

namespace poker 
{

StraightFlushCategorizer::StraightFlushCategorizer() 
{
	// TODO Auto-generated constructor stub

}

StraightFlushCategorizer::~StraightFlushCategorizer() 
{
	// TODO Auto-generated destructor stub
}

// verify hand is (1) a straight and (2) a flush
bool StraightFlushCategorizer::doCategorize(Hand hand)
{
	//cout << "StraightFlushCategorizer::doCategorize" << endl;

	StraightCategorizer straightCategorizer;
	FlushCategorizer    flushCategorizer;

	bool straightflush = false;

	if ( straightCategorizer.doCategorize(hand) &&
	     flushCategorizer.doCategorize(hand) )
	{
		hand.setCategory(Hand::STRAIGHTFLUSH);
		straightflush = true;
	}

	return straightflush;	
}

} // namespace 'poker'
