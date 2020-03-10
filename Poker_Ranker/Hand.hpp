/**
 * Hand.hpp
 *
 *      Author: syvertsj
 */

#ifndef HAND_HPP_
#define HAND_HPP_

#include "Card.hpp"

namespace poker 
{

class Hand 
{
public:

	// number of cards in hand
	static const int NUMCARDS = 5;

	// define categories
	enum Category
	{
		UNCATEGORIZED,  //
		HIGHCARD,       //
		ONEPAIR,        // 
		TWOPAIR,        // 
		THREEOFAKIND,   //
		STRAIGHT,       //
		FLUSH,          //
		FULLHOUSE,      //
		FOUROFAKIND,    //
		STRAIGHTFLUSH   //
	};

	Hand();
	virtual ~Hand();
	void addCard(Card card);
	Card getCard(int index);
	void setCategory(Hand::Category category);
	Hand::Category getCategory() const;
	void showHand();
	void setCardCount(int count);
	int  getCardCount();
	void incrCardCount();
	void clear(); 

private:

	// counter of cards in hand
	int CARDCOUNT;

	// array of cards
	Card cards[NUMCARDS];

	// category of hand
	Hand::Category category;
};

} // namespace 'poker'

#endif /* HAND_HPP_ */
