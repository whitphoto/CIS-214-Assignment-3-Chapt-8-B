/****************************************
*		Nathan Whitchurch				*
*		CIS 214 C++						*
*		Programming Assignment #3		*
*										*
****************************************/

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <stdlib.h>
#include <iostream>
#include "bankaccount.h"

using namespace std;


class Portfolio
	{
		private:
			int clientNumber;
			BankAccount savings;
			BankAccount checking;
			float stockValue;
			float realEstateValue;
					
		public:
			Portfolio();
			Portfolio(BankAccount, BankAccount, float, float);
			Portfolio(int, BankAccount, BankAccount, float, float);
			void displayPortfolio();
			void compareHoldings();
			static void promptUser();
			float getRealEstateValue();
			float getStockValue();
			
		
	};
	
	
#endif
	
	
	
