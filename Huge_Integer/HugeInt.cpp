
#include "HugeInt.hpp"  
#include <cctype>       
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cmath>
using namespace std;

namespace hugeint
{

// default int conversion constructor 
HugeInt::HugeInt(int number) 
{
	int i;
	this->sign = "";

	
	// initialize array to zero
	for ( i = 0; i < HugeInt::SIZE; i++ )
	{
		this->integer[i] = 0;
	}

	// set sign
	if ( number < 0 )
	{
		this->sign = "-";
	}

	// put digit(s) into array from left to right
	for ( i = HugeInt::SIZE - 1; abs(number) != 0 && i >= 0; i-- )
	{
		this->integer[i] = abs(number) % 10;
		number = abs(number) / 10;
	}
}

// string conversion constructor 
HugeInt::HugeInt(const string &number)
{
	int i;
	int j;
	this->sign = "";

    // initialize array to zero
    for ( i = 0; i < HugeInt::SIZE; i++ )
    {
       this->integer[i] = 0;
    }

    // put digit(s) into array
    i = HugeInt::SIZE - number.size();
    j = 0; 
    for ( ; i < HugeInt::SIZE; i++, j++ )
    {
    	if ( number.at(j) == '-' )
		{
			this->sign = "-";
		}
      if ( isdigit(number.at(j)) ) 
		{
         this->integer[i] = number.at(j) - '0'; 
      }
    }
} 

HugeInt::~HugeInt() 
{

}

int HugeInt::getFirstDigit() const
{
	int i;

    for ( i = 0; ( this->integer[i] == 0 ) && ( i < HugeInt::SIZE ); i++ )
    {
		; 
    }

	return i-1;
}

string HugeInt::toString() const 
{
	string strnumber;
	char number[HugeInt::SIZE];
	number[HugeInt::SIZE] = '\0';
	int i;

   for ( i = 0; ( this->integer[i] == 0 ) && ( i < HugeInt::SIZE ); i++ )
   {
		number[i] = this->integer[i] + ' '; // blank leading zeros
   }

	int first = i; // store index of first digit

   if ( first == HugeInt::SIZE )
   {
		number[HugeInt::SIZE-1] = '0'; 

		// append char array to string
		strnumber.append(number, HugeInt::SIZE-1, HugeInt::SIZE-1);
	}
	else
	{
		// proceed from end to first non-zero element
   	for ( i = HugeInt::SIZE-1; i >= first; i-- ) 
		{
			number[i] = this->integer[i] + '0'; 
   	}

		// append char array to string
		strnumber.append(number, first, HugeInt::SIZE-1);
	}

	// prepend sign
	strnumber = this->sign + strnumber;

	return strnumber;
}

void HugeInt::operator = (const HugeInt &right)
{
	// copy integer array
	for ( int i = 0;  i < HugeInt::SIZE; i++ )
	{
		this->integer[i] = right.integer[i];
	}

	// copy sign
	this->sign = right.sign;
}

// 
// external functions 
//

HugeInt operator + (const HugeInt &left, const HugeInt &right) 
{
   HugeInt sum; 
   int carry = 0;

	if ( left.sign == "-" && right.sign != "-" )
	{
		sum = right - left;
	}
	else if ( left.sign != "-" && right.sign == "-" )
	{
		sum = left - right;
	}
	else // both operands have same sign
	{
		sum.integer[0] = 0;
   	for ( int i = HugeInt::SIZE - 1; i >= 0; i-- ) 
		{
      	sum.integer[i] = left.integer[i] + right.integer[i] + carry;
	
      	// determine whether to carry a 1
      	if ( sum.integer[i] > 9 ) 
			{
         	sum.integer[i] -= 10;  
         	carry = 1;
      	} 
			else 
			{
         	carry = 0;
      	}
   	} 
	
		// set sign
		if ( left.sign == "-" )
		{
			sum.sign = "-";
		}
		else
		{
			sum.sign = "";
		}
   } 

   return sum; 
} 

HugeInt operator - (const HugeInt &left, const HugeInt &right) 
{
   HugeInt remainder; 
   int carry = 0;

	if ( left == right )
	{
		remainder.integer[HugeInt::SIZE-1] = 0;	
	}
	else if ( left > right )
	{
   	for ( int i = HugeInt::SIZE - 1; i >= 0; i-- ) 
		{
      	remainder.integer[i] = left.integer[i] - right.integer[i] - carry;

      	// determine whether to carry a 1
      	if ( remainder.integer[i] < 0 ) 
			{
				remainder.integer[i] = left.integer[i] + 10 - right.integer[i];
				carry = 1;
      	}  
			else 
			{
				carry = 0;
      	}
   	} 
		remainder.sign = "";
   } 
   else if ( left < right )
	{
   	for ( int i = HugeInt::SIZE - 1; i >= 0; i-- ) 
		{
      	remainder.integer[i] = right.integer[i] - left.integer[i] - carry;

      	// determine whether to carry a 1
      	if ( remainder.integer[i] < 0 ) 
			{
				remainder.integer[i] = right.integer[i] + 10 - left.integer[i];
				carry = 1;
      	}  
			else 
			{
				carry = 0;
      	}
   	} 
		remainder.sign = "-";
   } 

   return remainder; 
}

// add multiplicand number of times specified by multiplier
// alternatively, could do the inverse
HugeInt operator * (const HugeInt &left, const HugeInt &right)
{
	HugeInt product;

	// add left operand right times
	for ( int i = 0; i < right; i = i + 1 )
	{
		product = product + left;
	}

	// set sign of product
	if ( left.sign == "-" && right.sign == "" )
	{
		product.sign = "-";
	}
	else if ( left.sign == "" && right.sign == "-" )
	{
		product.sign = "-";
	}
	else
	{
		product.sign = "";
	}

	return product; 
}

// count number of subtractions of divisor from dividend until result is < 0
// alternatively, the dividend could be added to itself until result > 0
HugeInt operator / (const HugeInt &numerator, const HugeInt &divisor)
{
	HugeInt dividend = numerator; 
	HugeInt quotient; 

	while ( dividend > divisor || dividend == divisor )
	{
		dividend = dividend - divisor;
		quotient = quotient + 1;
	}

	// set sign of product
	if ( numerator.sign == "-" && divisor.sign == "" )
	{
		quotient.sign = "-";
	}
	else if ( numerator.sign == "" && divisor.sign == "-" )
	{
		quotient.sign = "-";
	}
	else
	{
		quotient.sign = "";
	}

	return quotient;
}

bool operator > (const HugeInt &left, const HugeInt &right)
{
	bool greater = false;
	int lindex   = left.getFirstDigit();
	int rindex   = right.getFirstDigit();

	if ( lindex < rindex )        // quick comparison of first indeces
	{
		greater = true;
	}
	else if ( lindex == rindex )  // compare elements of arrays
	{
		// update to iterate through arrays to compare each element
		for ( int i = lindex;  i < HugeInt::SIZE; i++ )
		{
			if ( left.integer[i] > right.integer[i] )
			{
				greater = true;
				break;
			}
		}
	}

	return greater;
}

bool operator < (const HugeInt &left, const HugeInt &right)
{
	bool less  = false;
	int lindex = left.getFirstDigit();
	int rindex = right.getFirstDigit();

	if ( lindex > rindex )        // quick comparison of first indeces
	{
		less = true;
	}
	else if ( lindex == rindex )  // compare elements of arrays
	{
		// update to iterate through arrays to compare each element
		for ( int i = lindex;  i < HugeInt::SIZE; i++ )
		{
			if ( left.integer[i] < right.integer[i] )
			{
				less = true;
				break;
			}
		}
	}

	return less;
}

bool operator == (const HugeInt &left, const HugeInt &right)
{
	bool equal = true;
	int lindex = left.getFirstDigit();
	int rindex = right.getFirstDigit();

	if ( lindex != rindex )        // quick comparison of first indeces
	{
		equal = false;
	}
	else if ( lindex == rindex )  // compare elements of arrays
	{
		// update to iterate through arrays to compare each element
		for ( int i = lindex;  i < HugeInt::SIZE; i++ )
		{
			if (  ( left.integer[i] < right.integer[i] )
			   || ( left.integer[i] > right.integer[i] ) )
			{
				equal = false;
				break;
			}
		}
	}

	return equal;
}

bool operator != (const HugeInt &left, const HugeInt &right)
{
	bool notequal = false;
	int lindex = left.getFirstDigit();
	int rindex = right.getFirstDigit();

	if ( lindex != rindex )        // quick comparison of first indeces
	{
		notequal = true;
	}
	else if ( lindex == rindex )  // compare elements of arrays
	{
		// update to iterate through arrays to compare each element
		for ( int i = lindex;  i < HugeInt::SIZE; i++ )
		{
			if (  ( left.integer[i] < right.integer[i] )
			   || ( left.integer[i] > right.integer[i] ) )
			{
				notequal = true;
				break;
			}
		}
	}

	return notequal;
}

// overloaded output operator
ostream& operator << ( ostream &output, const HugeInt &num )
{
   int i;

   for ( i = 0; ( num.integer[i] == 0 ) && ( i <= HugeInt::SIZE ); i++ )
   {
      ; 
   }

   if ( i == HugeInt::SIZE )
   {
      output << 0;
   }
   else
   {
      for ( ; i < HugeInt::SIZE; i++ )
      {
         output << num.integer[i];
      }
   }

   return output;
} 

} // namespace 'hugeint'
