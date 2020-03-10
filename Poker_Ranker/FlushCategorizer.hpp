/*
 * FlushCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef FLUSHCATEGORIZER_HPP_
#define FLUSHCATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker 
{

class FlushCategorizer: public poker::Categorizer 
{
public:
	FlushCategorizer();
	virtual ~FlushCategorizer();
	virtual bool doCategorize(Hand hand);
};

} // namespace 'poker'

#endif /* FLUSHCATEGORIZER_HPP_ */
