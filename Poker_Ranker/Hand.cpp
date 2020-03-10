/**
 * Hand.cpp
 *
 *      Author: syvertsj
 */

#include "Hand.hpp"
#include <stdlib.h>

namespace poker
{

Hand::Hand()
{
	Hand::CARDCOUNT = 0;
	this->setCategory(Hand::UNCATEGORIZED);
}

Hand::~Hand()
{
	// TODO Auto-generated destructor stub
}

void Hand::setCategory(Hand::Category category)
{
	this->category = category;
}

Hand::Category Hand::getCategory() const
{
	return this->category;
}

void Hand::setCardCount(int count)
{
	this->CARDCOUNT = count;
}

int Hand::getCardCount()
{
	return this->CARDCOUNT;
}

void Hand::incrCardCount()
{
	this->CARDCOUNT++;
}

void Hand::addCard(Card card)
{
	this->cards[this->getCardCount()] = card;
	this->incrCardCount();
	this->setCategory(Hand::UNCATEGORIZED);
}

// return card from card array 
Card Hand::getCard(int index)
{
	if (index < 0 || index >= NUMCARDS)
	{
		cout << "card index out of range... terminating..." << endl;
		exit(-1);
	} 

	return this->cards[index]; 
}

void Hand::showHand()
{
	for (int i = 0; i < Hand::NUMCARDS; i++)
	{
		cout << this->cards[i].getCard() << " ";
	}
	cout << endl;
}

void Hand::clear()
{
	this->setCardCount(0);
	this->setCategory(Hand::UNCATEGORIZED);
}

} // namespace 'poker'
