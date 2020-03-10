/**
 * PokerRanker.hpp
 *
 *      Author: syvertsj
 */

#ifndef POKERRANKER_HPP_
#define POKERRANKER_HPP_

#include "Hand.hpp"
#include "Categorizer.hpp"
#include "StraightFlushCategorizer.hpp"
#include "FourOfAKindCategorizer.hpp"
#include "FullHouseCategorizer.hpp"
#include "FlushCategorizer.hpp"
#include "StraightCategorizer.hpp"
#include "ThreeOfAKindCategorizer.hpp"
#include "TwoPairCategorizer.hpp"
#include "OnePairCategorizer.hpp"

#include <iostream>

namespace poker 
{

// type of input file parsing:
namespace dealer 
{
	static const int LIBCONFIG = 1;
	static const int STANDARD  = 2;
	static const int MAX_CARDS_PER_HAND = 4;
} // inner namespace 'dealer'

class PokerRanker 
{
public:
	PokerRanker();
	virtual ~PokerRanker();
	void useDealer(int option);
	void useLibConfig(char *configFile);      // use libconfig data file
	void useStandardConfig(char *configFile); // use simpler data file
	void compareHands(Hand hand1, Hand hand2);
	void categorize(Hand hand);
	inline virtual Categorizer * const* getCategorizers() const;

private:
	// number of categorizers (not including high card or uncategorized)
	static const int NUMCATEGORIZERS = 8; 

	// array of categorizers
	Categorizer *categorizer[NUMCATEGORIZERS];
};

Categorizer * const* PokerRanker::getCategorizers() const
{
   return this->categorizer;
}

} // namespace 'poker'

#endif /* POKERRANKER_HPP_ */
