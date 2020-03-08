
#ifndef HUGEINT_HPP
#define HUGEINT_HPP

#include <iostream>
#include <string>
using namespace std;

namespace hugeint
{

class HugeInt
{
public:
	// conversion constructors
   HugeInt(int number = 0);
   HugeInt(const string &number);

   virtual ~HugeInt();

   // return index of first digit
   int getFirstDigit() const;

   // return string
   string toString() const;

   // overloaded assignment
   void operator = (const HugeInt &right);

   static const int SIZE = 50;
   int integer[SIZE];
   string sign;
};

// prototypes for non-member operations being overloaded
HugeInt operator + (const HugeInt &left, const HugeInt &right);
HugeInt operator - (const HugeInt &left, const HugeInt &right);
HugeInt operator * (const HugeInt &left, const HugeInt &right);
HugeInt operator / (const HugeInt &numerator, const HugeInt &divisor); 
bool operator > (const HugeInt &left, const HugeInt &right);
bool operator < (const HugeInt &left, const HugeInt &right);
bool operator == (const HugeInt &left, const HugeInt &right);
bool operator != (const HugeInt &left, const HugeInt &right);
ostream & operator << (ostream &output, const HugeInt &num);

} // namespace 'hugeint'

#endif // HUGEINT_HPP
