/*
 * OnePairCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef ONEPAIRCATEGORIZER_HPP_
#define ONEPAIRCATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker 
{

class OnePairCategorizer: public poker::Categorizer 
{
public:
	OnePairCategorizer();
	virtual ~OnePairCategorizer();
	virtual bool doCategorize(Hand hand);
};

} // namespace 'poker'

#endif /* ONEPAIRCATEGORIZER_HPP_ */
