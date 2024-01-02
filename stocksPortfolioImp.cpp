/*
Name:  NSHE: , CLASS-SECTION: CS202, ASSIGNMENT: 3
Description: In investing, what is comfortable is rarely profitable.
Input: Develop stockInvestor(base class) that can be useful to set 
firstName, lastName and ID; set the investors data using setters or 
constructors from stockInvestors class; 
investorType is a derived (inheritance: is-a relationship) class from 
stockInvestor class and is useful to set the investor type, stock name, 
number of stocks, and stock price; 
stocksPortfolio is a base class with an object of other 
class(investorType) (Composition: has-a relationshipinvestorType).
stocksPortfolio is to set 3 different prices;
Output: Write the investors data to a file(investorsData.txt) following 
the driver code in stocksMain.cpp. The objects declaration of different 
classes, using constructors, setters, member functions to calculate the
portfolio of each investor. The investors' portfolios (reports) are 
printed on terminal.
In fileIO:
This class has only one member function. The member function returns the 
number of entries
Read the data from (investorsData.txt) file; use constructors, setters, 
member functions to calculate the portfolio of each investor. Finally,
write the investors' portfolios (reports) to an outputfile 
(investorsPortfolio.txt). 
*/
#include "stocksPortfolio.h"

stocksPortfolio::stocksPortfolio(){
    priceOne=0 ; 
    priceTwo=0; 
    priceThree=0;
    stockValue=0;  
    investorType invTypeObj; 
}

stocksPortfolio::stocksPortfolio(double pOne, double pTwo, double pThree, investorType invTemp){

    priceOne=pOne;
    priceTwo=pTwo;
    priceThree=pThree;
    investorType invTypeObj=invTemp; // is this right ?

}

void stocksPortfolio::setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp){
    priceOne=pOne;
    priceTwo=pTwo;
    priceThree=pThree;
    investorType invTypeObj=invTemp;//ask if this is right 
}

void stocksPortfolio::printPriceChanges(ostream &output) const{
    output<<"Price Changes:"<<"\t"<<priceOne<<"\t"<<priceTwo<<"\t"<<priceThree<<endl;
}
void stocksPortfolio::calculateStockValue(investorType invTemp, ostream &output){
    double initialSV =invTemp.getStockPrice()*invTemp.getStockCount();
    double price1= priceOne*invTemp.getStockCount();
    double price2= priceTwo*invTemp.getStockCount();
    double price3= priceThree*invTemp.getStockCount();//ONLY USE THIS
    double diff3= price3 - initialSV;
    if(!invTypeObj.checkInvestorID(invTemp.getID())||invTemp.getStockCount()<0||invTemp.getStockPrice()<0){
     initialSV =0;//set everything to 0 if error 
     price1= 0;
     price2= 0;
     price3= 0;
     diff3=0;
    }
    output<<endl;//spacing
    output<<"Stock Value with investor Price: "<<fixed<<setprecision(2)<<initialSV<<endl;
    output<<"Stock Value with a priceOne change: "<<price1<<endl;
    output<<"Stock Value with a priceTwo change: "<<price2<<endl;
    output<<"Stock Value with a priceThree change: "<<price3<<endl;
    if(price3<initialSV){//this is if u have a loss
        output<<"Final Stock Value: "<<diff3<<endl;
        output<<"Loss on an investment: "<<-diff3<<endl;
    }else{
        output<<"Final Stock Value: "<<price3<<endl;
        output<<"Profit on an investment: "<<diff3<<endl;
    }
    printPriceChanges(output);  
    output<<endl;
    string stars; 
    stars.append(65, '*'); //print some stars
    output << stars << endl;
}

void stocksPortfolio::writePriceChangesToFile(ostream &output) const{
    output<<priceOne<<setw(10)<<priceTwo<<setw(10)<<priceThree<<endl;
    //set wideths for last three

}

double stocksPortfolio::getInvestorPrice() const{
    return invTypeObj.getStockCount()*invTypeObj.getStockPrice();
}

double stocksPortfolio::getPriceOne() const{
    return priceOne;
}
double stocksPortfolio::getPriceTwo() const{
    return priceTwo;
}
double stocksPortfolio::getPriceThree() const{
    return priceThree;
}
double stocksPortfolio::getStockValue() const{
    return stockValue;

}