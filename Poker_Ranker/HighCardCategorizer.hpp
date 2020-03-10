/*
 * HighCardCategorizer.hpp
 *
 *      Author: syvertsj
 */

#ifndef HIGHCARDCATEGORIZER_HPP_
#define HIGHCARDCATEGORIZER_HPP_

#include "Categorizer.hpp"

namespace poker 
{

class HighCardCategorizer: public poker::Categorizer 
{
public:
	HighCardCategorizer();
	virtual ~HighCardCategorizer();
	virtual bool doCategorize(Hand hand);
};

} // namespace 'poker'

#endif /* HIGHCARDCATEGORIZER_HPP_ */
