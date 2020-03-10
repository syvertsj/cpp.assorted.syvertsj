/*
 * StraightCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef STRAIGHTCATEGORIZER_HPP_
#define STRAIGHTCATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker 
{

class StraightCategorizer: public poker::Categorizer 
{
public:
	StraightCategorizer();
	virtual ~StraightCategorizer();
	virtual bool doCategorize(Hand hand);
};

} // namespace 'poker'

#endif /* STRAIGHTCATEGORIZER_HPP_ */
