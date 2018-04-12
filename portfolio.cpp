/****************************************
*		Nathan Whitchurch				*
*		CIS 214 C++						*
*		Programming Assignment #3		*
*										*
****************************************/

#include "portfolio.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


Portfolio::Portfolio()
{
}

Portfolio::Portfolio(BankAccount savingsIn, BankAccount checkingIn, float stockIn, float realIn)
	{
		savings = savingsIn;
		checking = checkingIn;
		stockValue = stockIn;
		realEstateValue = realIn;
		
	} // End Constructor
	
Portfolio::Portfolio(int custNum, BankAccount savingsIn, BankAccount checkingIn, float stockIn, float realIn)
	{
		clientNumber = custNum;
		savings = savingsIn;
		checking = checkingIn;
		stockValue = stockIn;
		realEstateValue = realIn;
		
	} // End Constructor
	
	
void Portfolio::displayPortfolio()
	{
		this->savings.displayAccount();
		this->checking.displayAccount();
		
	} // End displayPortfolio();
	
	
	

void Portfolio::compareHoldings()
	{
		float totals;
		totals = this->savings.getBalance() + this->checking.getBalance() + this->stockValue + this->realEstateValue;
		
	
		
		if(this->savings.getBalance() >= (totals * 0.4))
			{cout << endl << "Your Savings are more than 40% of your total holdings.\nYour portfolio might be out of balance." << endl;}
		
		if(this->checking.getBalance() >= (totals * 0.4))
			{cout << endl << "Your Checking is more than 40% of your total holdings.\nYour portfolio might be out of balance." << endl;}
			
		if(this->stockValue >= (totals * 0.4))
			{cout << endl << "Your Stock is more than 40% of your total holdings.\nYour portfolio might be out of balance." << endl;}

		if(this->realEstateValue >= (totals * 0.4))
			{cout << endl << "Your Real Estate is more than 40% of your total holdings.\nYour portfolio might be out of balance." << endl;}
	} // End compareHoldings
	
void Portfolio::promptUser()
	{
		
		int custID = 0;
	
		
		while (custID >= 0)
			
			{
				cout << endl << "\nEnter a Customer ID number or a negative number to exit: ";
					
				cin >> custID;
				if(custID < 0)	// early break if the user enters a negative number at this
					{break;}	// point, since we're already inside the while loops. 
				
				Portfolio* port = new Portfolio();
				cout << endl;
				port->clientNumber = custID;
				cout << endl;
				port->savings = port->savings.chap8Init("Savings");
				cout << endl;
				port->checking = port->checking.chap8Init("Checking");
				cout << endl;
				cout << "\nEnter Stock Holdings: ";
				cin >> port->stockValue;
				cout << "\nEnter Real Estate Holdings: ";
				cin >> port->realEstateValue;
				
				port->displayPortfolio();
				port->compareHoldings();
				cout << endl;
				cout << "\nYour Stock Holdings are: $" << port->getStockValue();
				cout << endl;
				cout << "\nYour Real Estate Holdings are: $" << port->getRealEstateValue();		
			}
	} // End Promptuser
	
	
float Portfolio::getStockValue()
	{
		return stockValue;
	} // End getStockVallue
	
float Portfolio::getRealEstateValue()
	{
		return realEstateValue;
	} // End GetRealEstateValue
	
	
	
