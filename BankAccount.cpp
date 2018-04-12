/****************************************
*		Nathan Whitchurch				*
*		CIS 214 C++						*
*		Programming Assignment #3		*
*										*
****************************************/

#include "bankaccount.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


BankAccount::BankAccount()
	{
		// Default Constructor	
		
	}

BankAccount::BankAccount(int a, float b)
	{
		accountNumber = a;
		accountBalance = b;
		annualInterest = 0;
		
	} // End of Constructor w/two passed variables


BankAccount::BankAccount(int accountIn, float balIn, float rateIn, string acctIn)
	{
		
		accountNumber = accountIn;
		accountBalance = balIn;
		annualInterest = rateIn;
		acctType = acctIn;

	} // End of constructor w/three passed variables


BankAccount BankAccount::enterAccountData()
	{
		bool acctNumValid = false; 
		int accountIn;
		bool acctBalPos = false;
		float balanceIn;
		
		
		while(acctNumValid == false)
		
			{//begin while loop
				
				cout << endl << "Please enter an account number between 1 and 1000 ";
				cin >> accountIn;
				
				if (accountIn > 0 and accountIn < 1001)
					{//begin if loop
						acctNumValid = true;
					}//end if loop
					
			}//end while loop
		
		
		while(acctBalPos == false)
		
			{//begin while loop
				
				cout << endl << "Please positive balance amount ";
				cin >> balanceIn;
				
				if (accountIn > 0)
					{//begin if loop
						acctBalPos = true;
					}//end if loop
					
			}//end while loop
		
		BankAccount bankIn (accountIn, balanceIn);
		return bankIn;
			 
	}// End of enterAccountData()
	
	
	
void BankAccount::displayAccount()
	{
		cout.setf(ios::fixed);	// These two statements ensure that the values
		cout.precision(2);		// will be displayed without exponents and with only 
								// two decimal points.		
		
		cout << endl << "The balance of " << acctType <<" account number ";
		cout << this->accountNumber;
		cout << " is $";
		cout << this->accountBalance;
		cout << " with an interest rate of " << this->annualInterest << "%";
			
	} // End of displayAccount()
	
void BankAccount::computeInterest(BankAccount arr[10], int count, int years)
	{
		int numAccount = count;
		int countYears = years;
		for(count = 0; count < numAccount; count++)
			{			
				float compounded = arr[count].accountBalance;
					for(int i = 0; i < countYears; i++)
						{
							compounded = compounded * ((arr[count].annualInterest / 100) + 1);
						}
						
				cout << endl << "Compounded interest for account number " << arr[count].accountNumber << " over " << years << " years adds up to " << compounded;
			}
	}// End of computeInterest
				
void BankAccount::fillArray()

	{
			int numOfAccounts = 0;	//used later to access only the filled spots in the array
			
			BankAccount bankArray[10];
				
			int accountCounter = 0; // used to make sure the while loop
			while(numOfAccounts < 10)//stops at 10 accounts, the max size of the array
				{		
					int validChoice = 2;					
							
					bankArray[numOfAccounts] = BankAccount::enterAccountData(); 
					// fills the spot in the array with the new BankAccount object returned from 
					// the enterAccountData function
					
					numOfAccounts++;
					
					while(validChoice < 0 or validChoice > 1)
						{
							cout << endl << "Do you wish to make another bank account? please type 0 for NO or 1 for YES: ";
							cin >> validChoice;							
						}// End while
							
					if(validChoice == 0)
					{break;} //Breaks out of loop if 0 is entered for validChoice
			
				}// End While Loop 
	}// End of fillArray()
				
				
BankAccount BankAccount::chap8Init(string typeIn)

	{
		int accountCheck;
		int accountOut;
		float balOut= 0;
		float rateOut = 0;
		string acctType = typeIn;
		cout << "\nPlease Enter your " << acctType << " Account number: ";
		cin >> accountCheck;
			if (accountCheck >= 1000 and accountCheck <= 9999)
				{accountOut= accountCheck;}
			else
				{accountOut = 0;
				cout << "\nAccount number out of range, defaulted to 0 ";}
		
		cout << "\nPlease enter your positive account balance: ";
		cin >> balOut;
		
		cout << "\nPlease enter your interest rate as a whole percentage: ";
		cin >> rateOut;
		
		BankAccount BankIn (accountOut, balOut, rateOut, acctType);	
		return BankIn;
		
		
		
	}
		
		
float BankAccount::getBalance()
	{
		return this->accountBalance;
	}
//end of BankAccount.cpp	
	
	
