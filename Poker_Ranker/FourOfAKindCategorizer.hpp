/*
 * FourOfAKindCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef FOUROFAKINDCATEGORIZER_HPP_
#define FOUROFAKINDCATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker {

class FourOfAKindCategorizer: public poker::Categorizer {
public:
	FourOfAKindCategorizer();
	virtual ~FourOfAKindCategorizer();
	virtual bool doCategorize(Hand hand);
};

}

#endif /* FOUROFAKINDCATEGORIZER_HPP_ */
