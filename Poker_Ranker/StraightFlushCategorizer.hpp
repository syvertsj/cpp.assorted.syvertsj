/*
 * StraightFlushCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef STRAIGHTFLUSHCATEGORIZER_HPP_
#define STRAIGHTFLUSHCATEGORIZER_HPP_

#include "Categorizer.hpp"
#include "StraightCategorizer.hpp"
#include "FlushCategorizer.hpp" 

namespace poker 
{

class StraightFlushCategorizer: public poker::Categorizer 
{
public:
	StraightFlushCategorizer();
	virtual ~StraightFlushCategorizer();
	virtual bool doCategorize(Hand hand);
};

} // namespace 'poker'

#endif /* STRAIGHTFLUSHCATEGORIZER_HPP_ */
