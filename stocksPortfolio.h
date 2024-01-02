#ifndef STOCKSPORTFOLIO_H
#define STOCKSPORTFOLIO_H
#include<fstream>
#include<iomanip>
#include "investorType.h"

class stocksPortfolio{
private:
    double priceOne; 
    double priceTwo;  
    double priceThree;  
    double stockValue; 
    investorType invTypeObj;

public:
	stocksPortfolio(); 
	stocksPortfolio(double pOne, double pTwo, double pThree, investorType invTemp);
	
	void setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp);
	
        void printPriceChanges(ostream &output) const;
    
	void calculateStockValue(investorType invTemp, ostream &output);
	
	void writePriceChangesToFile(ostream &output) const; 
	
	
	double getInvestorPrice() const; 
	double getPriceOne() const;
	double getPriceTwo() const;
	double getPriceThree() const;
	double getStockValue() const;
    
	
};

#endif
