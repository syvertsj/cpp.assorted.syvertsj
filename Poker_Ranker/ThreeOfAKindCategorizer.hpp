/*
 * ThreeOfAKindCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef THREEOFAKINDCATEGORIZER_HPP_
#define THREEOFAKINDCATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker 
{

class ThreeOfAKindCategorizer: public poker::Categorizer 
{
public:
	ThreeOfAKindCategorizer();
	virtual ~ThreeOfAKindCategorizer();
	virtual bool doCategorize(Hand hand);
};

} // namespace 'poker'

#endif /* THREEOFAKINDCATEGORIZER_HPP_ */
