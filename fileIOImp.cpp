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
#include "fileIO.h"


    unsigned int fileIO::readWriteDataFile(ifstream &inFile, ofstream &outData){
        string line=" ";
        string id =" "; 
        double stkcnt=0; 
        double stkprice=0; 
        double pch1=0; 
        double pch2=0; 
        double pch3=0;
        string fn = " "; 
        string ln = " "; 
        string invt = " "; 
        string name = " ";
        unsigned int i=0;
        getline(inFile, line);

        while(inFile>>id>>fn>>ln>>invt>>name>>stkcnt>>stkprice>>pch1>>pch2>>pch3){
            investorType obj(id,fn,ln,invt,name,int(stkcnt),stkprice,outData);
            stocksPortfolio objj; //probably an issue
            obj.print(outData);
            objj.setPortfolio(pch1,pch2,pch3,obj);
            objj.calculateStockValue(obj,outData);
            i++;

        }
        string stars; 
        stars.append(65, '*'); 
        outData<<endl;
        outData<<endl;
        outData << stars << endl;//maybe change to outFile
        cout<<"Total Entries: "<<i<<endl;
        outData<<"Total Entries: "<<i<<endl;

        return i;



    }