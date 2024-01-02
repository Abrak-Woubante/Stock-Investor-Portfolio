#ifndef STOCKSPORTFOLIO_H
#define STOCKSPORTFOLIO_H
#include<fstream>
#include<iomanip>
#include "investorType.h"

class stocksPortfolio{
private:
    double priceOne;  //variable to store the priceOne
    double priceTwo;  //variable to store the priceTwo
    double priceThree;  //variable to store the priceThree
    double stockValue;  //variable to store the stockValue
    investorType invTypeObj; // object of investorType (Composition)

public:
	stocksPortfolio(); //Default constructor
	stocksPortfolio(double pOne, double pTwo, double pThree, investorType invTemp);
	//parameterized constructor
  	//Initialize the private member varaibles: priceOne, priceTwo, and priceThree 
  	//according to the parameters
  	//Initialize private member object of other class according to the given parameter
	
	void setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp);
	//Initialize the private member varaibles: priceOne, priceTwo, and priceThree 
  	//according to the parameters
  	//Initialize private member object of other class according to the given parameter

    //To print three price changes
    void printPriceChanges(ostream &output) const;
    
	void calculateStockValue(investorType invTemp, ostream &output);
	//Calculate stockValue- multiply stockPrice with stockCount 
							//(both from investor type; use getters)
	//multiply stockCount with each new price and print statements accordingly
	//Finally print stockValue - Show Loss/Profit accordingly
	//Check sample output for more details 


	void writePriceChangesToFile(ostream &output) const; 
	//Write priceOne, priceTwo, and priceThree to the investorsData.txt
	//Check sample output, the prices should be in same line as id, name, etc.
	
	double getInvestorPrice() const; //get investor price from investorType
	double getPriceOne() const;
	double getPriceTwo() const;
	double getPriceThree() const;
	double getStockValue() const;
    //getter(Accessor) functions to return private member variables
    //accordingly
	
};

#endif
