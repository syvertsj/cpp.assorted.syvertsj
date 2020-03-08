
// Test HugeInt class

#include "HugeInt.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace hugeint;

int main(int argc, char* argv[])
{
   string number1; 
   string number2;
   char operation;
   string option;

   do  // get user input
	{ 
      try 
		{ 
         cout << "Enter a valid equation: "; 
         cin >> number1 >> operation >> number2;
      } 
		catch (exception &e) 
		{ 
         cout << "Invalid arithmetic expression" << endl;
         continue;
      }

    	HugeInt hi1(number1); 
		HugeInt hi2(number2);
		HugeInt result;

    	switch (operation) 
		{
         case '+': 
				result = hi1 + hi2; 
				break; 
         case '-': 
				result = hi1 - hi2; 
				break; 
         case '*': 
				result = hi1 * hi2; 
				break; 
         case '/': 
				result = hi1 / hi2;
				break; 
         default:  
				continue; 
		}

		cout << number1 << operation << number2 << " = " << result.sign << result << endl; 

		cout << "Continue? [y|n]: ";
		cin >> option;
		if (option.at(0) == 'n' || option.at(0) == 'N') 
		{
			cout << argv[0] << " exiting... " << endl;
			break;
		} 
		else 
		{
			continue;
		}

   } while ( true );

	return EXIT_SUCCESS;
} 

