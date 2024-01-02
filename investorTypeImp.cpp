/*
Name: Wouabante,Abrak NSHE: 5007305246, CLASS-SECTION: CS202, ASSIGNMENT: 3
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
#include "investorType.h"
#include<iostream>
#include<iomanip>

investorType::investorType(){
    typeName="";
    stockName="";
    stockCount=0;
    stockPrice=0;
}

 investorType::investorType(string id, string fName, string lName,
    string tyName, string stName, int stCount, double stPrice, 
    ostream &output):stockInvestor(fName,lName,id){
        setInvestorID(id);//set the id
        if(checkInvestorID(id)==false){//checkinh
            output<<"Invalid ID; No calculations for "<<fName<<"; ID "<<id<<endl;
        }else if(stCount<0){//connect my if statements so they can work
             output<<fName<<"'s stock count is invalid"<<endl;
        }else if(stPrice<0){ //check the price
            output<<fName<<"'s stock price is invalid"<<endl;
        }
        typeName=tyName;//set the others
        stockName=stName;
        stockCount=stCount;
        stockPrice=stPrice;
    }


    void investorType::setInvestorInfo(string id, string fName, string lName,
    string tyName, string stName, int stCount, double stPrice){
        setName(fName, lName);//switched these two for oscar
        setInvestorID(id);
        typeName=tyName;
        stockName=stName;//set the others
        stockCount=stCount;
        stockPrice=stPrice;
    }

    void investorType::setType(string tyName){
        typeName=tyName;//set the type
    }

    void investorType::setStockName(string stName){
        stockName=stName;//set stock name
    }

    void investorType::setStockCount(int stCount){
        stockCount=stCount;//set the stock count
    }

    void investorType::setStockPrice(double stPrice){
        stockPrice=stPrice;//set the stock price
    }

    string investorType::getID() const{
        return stockInvestor::getID();//get the id
    }

    string investorType::getFirstName() const{
        return stockInvestor::getFirstName();//first name from other clas
    }

    string investorType::getLastName() const{
        return stockInvestor::getLastName();//last name from other class
    }

    string investorType::getType() const{
        return typeName;//get the time
    }
    string investorType::getStockName() const{
        return stockName;//return the stock name
    }

    double investorType::getStockPrice() const{
        return stockPrice;//get the stock price
    }

    double investorType::getStockCount() const{
        return stockCount;//get the stockCount
    }

    void investorType::print(ostream &outFile) const{
        outFile <<fixed<<showpoint<<setprecision(2);//for first line
        outFile<<endl;//spacing
        string dashes;//print dashes
        dashes.append(50,'_');//make 50 if them
        string stars; 
        stars.append(65, '*'); //make 65 starts
        outFile << stars << endl;//maybe change to outFile
        outFile<<"Investor Type:"<<endl;//print to ostream object
        outFile<<"Type Name: "<<getType()<<endl;
        outFile<<"Investor ID: "<<getID()<<endl;
        outFile<<"First Name: "<<getFirstName()<<endl;
        outFile<<"Last Name: "<<getLastName()<<endl;
        outFile<<endl; 
        outFile<<"Stock Name: "<<getStockName()<<endl;
        outFile<<"Stock Count: "<<getStockCount()<<endl;
        outFile<<"Stock Price: "<<getStockPrice()<<endl;
        outFile << dashes << endl;//print more dashes

    }

     void investorType::writeDataToFile(ofstream &outFile, investorType tempObj){
    
       outFile<<setw(10)<<tempObj.getID()<<setw(10)<<tempObj.getFirstName()<<setw(10)<<tempObj.getLastName()
        <<setw(10)<<typeName<<setw(10)<<stockName<<setw(12)<<double(stockCount)<<setw(12)<<stockPrice<<setw(10);

    }