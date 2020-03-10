/*
 * FullHouseCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef FULLHOUSECATEGORIZER_HPP_
#define FULLHOUSECATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker 
{

class FullHouseCategorizer: public poker::Categorizer 
{
public:
	FullHouseCategorizer();
	virtual ~FullHouseCategorizer();
	virtual bool doCategorize(Hand hand);
};

} // namespace 'poker'

#endif /* FULLHOUSECATEGORIZER_HPP_ */
