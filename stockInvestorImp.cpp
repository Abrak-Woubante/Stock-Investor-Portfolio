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
    if(investorIDTemp.length()<6){
        return false;
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
       output<<endl;//spacing
       output<<"Investor ID: "<<ID<<endl;//print
       output<<"First Name: "<<firstName<<endl;
       output<<"Last Name: "<<lastName<<endl;
     }

  
