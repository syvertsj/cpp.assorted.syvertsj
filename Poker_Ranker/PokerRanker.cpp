/**
 * PokerRanker.cpp
 *
 *      Author: syvertsj
 */

#include "PokerRanker.hpp"
#include "Card.hpp"
#include "Hand.hpp"

#include <iostream>
#include <fstream>
#include <string>

#include <libconfig.h>
#include <unistd.h>

using namespace std;

namespace poker 
{

PokerRanker::PokerRanker() 
{
	this->categorizer[0] = new StraightFlushCategorizer;
	this->categorizer[1] = new FourOfAKindCategorizer;
	this->categorizer[2] = new FullHouseCategorizer;
	this->categorizer[3] = new FlushCategorizer;
	this->categorizer[4] = new StraightCategorizer;
	this->categorizer[5] = new ThreeOfAKindCategorizer;
	this->categorizer[6] = new TwoPairCategorizer;
	this->categorizer[7] = new OnePairCategorizer;
}

PokerRanker::~PokerRanker() 
{
	// TODO Auto-generated destructor stub
}

void PokerRanker::useDealer(int option)
{
	if (dealer::LIBCONFIG == option)
	{
		useLibConfig( (char *)"../pokerhands.cfg" );
	}
	else if (dealer::STANDARD == option)
	{
		useStandardConfig( (char *)"../pokerhands.txt" );
	}
}

// modification of example(s) from libconfig package
void PokerRanker::useLibConfig(char *configFile)
{
	string token;
	int cardCount = 0; // cards per hand
	int turn = 0;      // toggle turns for dealing hands
	Hand hand1; 
	Hand hand2;

	config_t cfg;
	config_setting_t *setting;
	const char *str;

	config_init(&cfg);

	// Read the file. If there is an error, report it and exit.
	// better if throwing an exception...
	if(! config_read_file(&cfg, configFile))
	{
	  fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
	          config_error_line(&cfg), config_error_text(&cfg));
	  config_destroy(&cfg);
	}

	// Get application name
	if(config_lookup_string(&cfg, "name", &str))
	{
	  printf("Application name: %s\n\n", str);
	}
	else 
	{
	  fprintf(stderr, "No 'name' setting in configuration file.\n");
	}

	// Output cards
	setting = config_lookup(&cfg, "hands.cards");
	if(setting != NULL)
	{
	  int count = config_setting_length(setting);
	  int i;

	  int cards_per_hand = 0;

	  for(i = 0; i < count; ++i, ++cards_per_hand)
	  {
	      config_setting_t *card = config_setting_get_elem(setting, i);

	      // attributes of a card
	      const char *rank, *suit;

	      if ( !(config_setting_lookup_string(card, "rank", &rank)
	           && config_setting_lookup_string(card, "suit", &suit) ) )
	      {
	        continue;
	      }

	      if (dealer::MAX_CARDS_PER_HAND < cards_per_hand)
	      {
	    	  cards_per_hand = 0;
	    	  cout << endl;
	      }
	      token = string(rank) + string(suit);

			// form Card
			Card cardClass(token);
			//cout << cardClass.getCard() << " ";

			if ( 0 == (turn % 2) )
			{
				hand1.addCard(cardClass);	
			}
			else if ( 1 == (turn % 2) )
			{
				hand2.addCard(cardClass);	
			}

			cardCount++;
	
			if (cardCount > dealer::MAX_CARDS_PER_HAND)
			{
				cout << endl;
				if ( 1 == (turn % 2) )
				{
					// compare hands
					this->compareHands(hand1, hand2);
				}

				// toggle hand to deal
				turn++;  
				cardCount = 0;
				hand2.clear();
				hand1.clear();
				sleep(1);
			}
		}
		cout << endl;
		sleep(1);
	}

	config_destroy(&cfg);
}

// plain text parsing simpler than 'libconfig'!
void PokerRanker::useStandardConfig(char *configFile)
{
	ifstream fileHands(configFile, ios::in);
	string token;
	int cardCount = 0; // cards per hand
	int turn = 0;      // toggle turns for dealing hands
	Hand hand1;
	Hand hand2;

	while ( ! fileHands.eof() )
	{
		fileHands >> token;

		// form Card
		Card card(token);

		if ( 0 == (turn % 2) )
		{
			hand1.addCard(card);	
		}
		else if ( 1 == (turn % 2) )
		{
			hand2.addCard(card);	
		}

		cardCount++;

		if (cardCount > dealer::MAX_CARDS_PER_HAND)
		{
			cout << endl;
			if ( 1 == (turn % 2) )
			{
				// compare hands
				this->compareHands(hand1, hand2);
			}

			// toggle hand to deal
			turn++;  
			cardCount = 0;
			hand2.clear();
			hand1.clear();
			sleep(1);
		}
	}
}

void PokerRanker::compareHands(Hand hand1, Hand hand2)
{
	cout << "   Poker Ranker -- Compare Hands" << endl;
	
	Categorizer * const* categorizer = this->getCategorizers();

	//hand1.sort();
	cout << "hand1: " << endl;
	hand1.showHand();

	//hand2.sort();
	cout << "hand2: " << endl;
	hand2.showHand();

	int i = 0; 
	do         // categorize each hand
	{
      Categorizer *categorizer = this->categorizer[i];

      if( hand1.getCategory() == Hand::UNCATEGORIZED )
      {
         categorizer->doCategorize(hand1);
      }
      if( hand2.getCategory() == Hand::UNCATEGORIZED )
      {
         categorizer->doCategorize(hand2);
      }

      if (++i >= PokerRanker::NUMCATEGORIZERS) { break; }

   } while (hand1.getCategory() == Hand::UNCATEGORIZED  && hand2.getCategory() == Hand::UNCATEGORIZED);


	// compare hands
	if ( hand1.getCategory() > hand2.getCategory() )
	{
		cout << "  --> hand one wins" << endl;
	}
	else if ( hand1.getCategory() < hand2.getCategory() )
	{
		cout << "  --> hand two wins" << endl;
	}
	else 
	{
		// first, to do card-by-card comparison for winner
		// ...that might need to be done with respect to the category

		// else: tie
		cout << "  --> result is a tie" << endl;
	}
}

} // namespace 'poker'
