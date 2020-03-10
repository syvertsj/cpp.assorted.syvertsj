/**
 * Card.cpp
 *
 *      Author: syvertsj
 */

#include "Card.hpp"

namespace poker
{

Card::Card()
{
	// empty constructor (use with 'setCard' method later)
}

Card::Card(string token)
{
	if ( token.length() != Card::VALID_TOKEN )
	{
		cout << "invalid card" << endl;
	}
	else {
		this->token = token;
		this->setValue( token.at(0) );
		this->setSuit ( token.at(1) );
		this->setRank();
	}
}

Card::~Card()
{
	// TODO Auto-generated destructor stub
}

void Card::setCard(string token)
{
	this->token = token;
}

void Card::setValue(char value)
{
	this->value = value;
}

void Card::setSuit(char suit)
{
	this->suit = suit;
}

string Card::getCard()
{
	return this->token;
}

void Card::setRank()
{
	switch (this->value)
	{
		case '1':
			this->rank = 1;
			break;
		case '2':
			this->rank = 2;
			break;
		case '3':
			this->rank = 3;
			break;
		case '4':
			this->rank = 4;
			break;
		case '5':
			this->rank = 5;
			break;
		case '6':
			this->rank = 6;
			break;
		case '7':
			this->rank = 7;
			break;
		case '8':
			this->rank = 8;
			break;
		case '9':
			this->rank = 9;
			break;
		case '0':
			this->rank = 10;
			break;
		case 'J':
			this->rank = 11;
			break;
		case 'Q':
			this->rank = 12;
			break;
		case 'K':
			this->rank = 13;
			break;
		case 'A':
			this->rank = 14;
			break;
		default:
			cout << "unknown card value" << endl;
			break;
	}
}

char Card::getSuit ()
{
	return this->suit;
}

int Card::getRank()
{
	return this->rank;
}

} // namespace 'poker'
