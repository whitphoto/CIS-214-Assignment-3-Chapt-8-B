/****************************************
*		Nathan Whitchurch				*
*		CIS 214 C++						*
*		Programming Assignment #3		*
*										*
****************************************/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <stdlib.h>
#include <iostream>

using namespace std;

class BankAccount
	{
	 	private:
	 		// Variables
			int accountNumber;
	 		float accountBalance;
	 		float annualInterest;
	 		string acctType;
	 		
		
		public:
			
			// Constructors
			BankAccount();
			BankAccount(int, float);
			BankAccount(int, float, float, string);
						
			
			// Functions
			BankAccount static enterAccountData();
			static void computeInterest(BankAccount arr[10], int count, int years);
			void displayAccount();
			static void fillArray();
			static BankAccount chap8Init(string);
			float getBalance();
		
			
			
		

	 		
				
	};
	
#endif
