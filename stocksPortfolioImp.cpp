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
    investorType invTypeObj=invTemp; 

}

void stocksPortfolio::setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp){
    priceOne=pOne;
    priceTwo=pTwo;
    priceThree=pThree;
    investorType invTypeObj=invTemp;
}

void stocksPortfolio::printPriceChanges(ostream &output) const{
    output<<"Price Changes:"<<"\t"<<priceOne<<"\t"<<priceTwo<<"\t"<<priceThree<<endl;
}
void stocksPortfolio::calculateStockValue(investorType invTemp, ostream &output){
    double initialSV =invTemp.getStockPrice()*invTemp.getStockCount();
    double price1= priceOne*invTemp.getStockCount();
    double price2= priceTwo*invTemp.getStockCount();
    double price3= priceThree*invTemp.getStockCount();
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
    stars.append(65, '*'); 
    output << stars << endl;
}

void stocksPortfolio::writePriceChangesToFile(ostream &output) const{
    output<<priceOne<<setw(10)<<priceTwo<<setw(10)<<priceThree<<endl;
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
