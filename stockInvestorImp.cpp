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

#include "stockInvestor.h"
#include<iostream>

 stockInvestor::stockInvestor(){
    firstName="";//set to empty strings
    lastName="";
    ID="";
 }

  stockInvestor::stockInvestor(string fName, string lName, string id){
    firstName=fName;
    lastName=lName;
    ID=id;
  }

  void stockInvestor::setStockInvestor(string fName, string lName, string id){
    firstName=fName;
    lastName=lName;
    ID=id;

  }

  bool stockInvestor::checkInvestorID(string investorIDTemp) const{
    if(investorIDTemp.length()<6){//changed from 
        return false;//check for length
    }
   for(int i = 0 ; i <investorIDTemp.length();i++){
        if(investorIDTemp[0]< 65 || investorIDTemp[0]>90){
            return false;
        }else if(investorIDTemp[0] != 80 && investorIDTemp[0] != 84){
            return false;
        }
    }
    string sub= investorIDTemp.substr(1);
    for(int i = 0 ; i<sub.length();i++){
        if(sub[i]<0&&sub[i]>9){
            return false;
        }
    }

    return true;
  }

    void stockInvestor::setInvestorID(string id){
          ID=id;//set ID
        if(checkInvestorID(getID())==false){//changed from !
            cout<<"Error :- "<<id<<" is invalid investorID for "<<getFirstName()<<endl;
        }
    }

    void stockInvestor::setName(string fName, string lName){
            firstName=fName;
            lastName=lName;
    }

    string stockInvestor::getID() const{
        return ID;//get id access
    }

    string stockInvestor::getFirstName() const{
        return firstName;//return first name
    }

    string stockInvestor::getLastName() const{
        return lastName;//return lastname
    }

     void stockInvestor::print(ostream &output) const{
       // output<<firstName<<" "<<lastName<<" "<<ID;
       output<<endl;//spacing
       output<<"Investor ID: "<<ID<<endl;//print
       output<<"First Name: "<<firstName<<endl;
       output<<"Last Name: "<<lastName<<endl;
     }

  