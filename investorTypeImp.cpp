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
        setInvestorID(id);
        if(checkInvestorID(id)==false){
            output<<"Invalid ID; No calculations for "<<fName<<"; ID "<<id<<endl;
        }else if(stCount<0){
             output<<fName<<"'s stock count is invalid"<<endl;
        }else if(stPrice<0){ 
            output<<fName<<"'s stock price is invalid"<<endl;
        }
        typeName=tyName;
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
        typeName=tyName;
    }

    void investorType::setStockName(string stName){
        stockName=stName;
    }

    void investorType::setStockCount(int stCount){
        stockCount=stCount;
    }

    void investorType::setStockPrice(double stPrice){
        stockPrice=stPrice;
    }

    string investorType::getID() const{
        return stockInvestor::getID();
    }

    string investorType::getFirstName() const{
        return stockInvestor::getFirstName();
    }

    string investorType::getLastName() const{
        return stockInvestor::getLastName();
    }

    string investorType::getType() const{
        return typeName;
    }
    string investorType::getStockName() const{
        return stockName;
    }

    double investorType::getStockPrice() const{
        return stockPrice;
    }

    double investorType::getStockCount() const{
        return stockCount;
    }

    void investorType::print(ostream &outFile) const{
        outFile <<fixed<<showpoint<<setprecision(2);
        outFile<<endl;
        string dashes;
        dashes.append(50,'_');
        string stars; 
        stars.append(65, '*'); 
        outFile << stars << endl;
        outFile<<"Investor Type:"<<endl;
        outFile<<"Type Name: "<<getType()<<endl;
        outFile<<"Investor ID: "<<getID()<<endl;
        outFile<<"First Name: "<<getFirstName()<<endl;
        outFile<<"Last Name: "<<getLastName()<<endl;
        outFile<<endl; 
        outFile<<"Stock Name: "<<getStockName()<<endl;
        outFile<<"Stock Count: "<<getStockCount()<<endl;
        outFile<<"Stock Price: "<<getStockPrice()<<endl;
        outFile << dashes << endl;

    }

     void investorType::writeDataToFile(ofstream &outFile, investorType tempObj){
    
       outFile<<setw(10)<<tempObj.getID()<<setw(10)<<tempObj.getFirstName()<<setw(10)<<tempObj.getLastName()
        <<setw(10)<<typeName<<setw(10)<<stockName<<setw(12)<<double(stockCount)<<setw(12)<<stockPrice<<setw(10);

    }
