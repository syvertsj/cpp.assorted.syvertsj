/**
 * Card.hpp
 *
 *      Author: syvertsj
 */

#ifndef CARD_HPP_
#define CARD_HPP_

#include <string>
#include <iostream>

using namespace std;

namespace poker
{

class Card
{
public:
	static const int VALID_TOKEN = 2;
	Card();             // empty constructor
	Card(string token); // initializing constructor
	virtual ~Card();
	void setCard(string token); // set string repres.
	string getCard();           // get string repres.
	void setValue(char value);
	void setSuit (char suit);
	char getSuit ();
	int  getRank();

private:
	string token;
	char value;
	char suit;
	int  rank;
	void setRank();
};

} // namespace 'poker'

#endif /* CARD_HPP_ */
