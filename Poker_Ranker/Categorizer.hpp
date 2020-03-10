/**
 * Categorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef CATEGORIZER_HPP_
#define CATEGORIZER_HPP_

#include "Hand.hpp"
#include "Card.hpp"

namespace poker
{

// abstract base class
class Categorizer
{
public:
	Categorizer();
	virtual ~Categorizer();
	virtual bool doCategorize(Hand hand) = 0;
	int scanForMatch(Hand hand, Card card, int index);
};

} // namespace 'poker'

#endif /* CATEGORIZER_HPP_ */
