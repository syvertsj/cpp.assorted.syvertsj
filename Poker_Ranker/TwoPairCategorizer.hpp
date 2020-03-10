/*
 * TwoPairCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef TWOPAIRCATEGORIZER_HPP_
#define TWOPAIRCATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker 
{

class TwoPairCategorizer: public poker::Categorizer 
{
public:
	TwoPairCategorizer();
	virtual ~TwoPairCategorizer();
	virtual bool doCategorize(Hand hand);
	void setPairCount(int count);
};

} // namespace 'poker'

#endif /* TWOPAIRCATEGORIZER_HPP_ */
