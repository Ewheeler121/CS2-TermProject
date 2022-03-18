#pragma once

#include <string>
#include <time.h>

using namespace std;

enum AccountType{
    CHECKING,
    SAVINGS
};

class Customer{
public:

    //Basic Constructor
    Customer(){

        name = "NULL";
        dateOfBirth = "00/00/0000";
        SSN = "000-00-0000";
        address = "000 NULL";
        phoneNumber = "000-000-0000";

        checking = 0;
        saving = 0;
        lastDepositDate = "00/00/0000";

    }
    //constructor for CSV fill reader
    bool readCSV(string ICSV){
        int pastComma = 0;
        int marker = 0;
        string result = "";

        //Main Loop
        for(int i = 0; i < ICSV.length(); i++){

            //Finding the ','
            if(ICSV.at(i) == ','){
                for(int k = pastComma; k < i; k++){
                    result += ICSV.at(k);
                }
                pastComma = i + 1;

                //Setting the Result to the Proper Variable
                switch(marker){
                    case 0:
                        if(!setName(result))
                            return false;
                        marker++;
                        break;
                    case 1:
                        if(!setDateOfBirth(result))
                            return false;
                        marker++;
                        break;
                    case 2:
                        if(!setSSN(result))
                            return false;
                        marker++;
                        break;
                    case 3:
                        if(!setAddress(result))
                            return false;
                        marker++;
                        break;
                    case 4:
                        if(!setPhoneNumber(result))
                            return false;
                        marker++;
                        break;
                    case 5:
                        saving = stod(result);
                        marker++;
                        break;
                    case 6:
                        checking = stod(result);
                        marker++;
                        break;
                    case 7:
                        lastDepositDate = result;
                        marker++;
                        break;
                }
                result = "";
            }
        }
        return true;
    }
    //writing the line for the CSV file
    string getCSV(){
        string result = "";

        result += name + ',' + dateOfBirth + ',' + SSN + ',' + address + ',' + phoneNumber + ',' + to_string(saving) + ',' +
                  to_string(checking) + ',' + lastDepositDate;

        return result;
    }

    //Basic Getters
    string getName() const {return name;}
    string getDateOfBirth() const {return dateOfBirth;}
    string getSSN() const {return SSN;}
    string getAddress() const {return address;}
    string getPhoneNumber() const {return phoneNumber;}
    string getLastDeposit() const {return lastDepositDate;}

    //Setters with Checks
    bool setName(string Iname){if(findComma(Iname)){ name = Iname;return true;}else{return false;}}
    bool setDateOfBirth(string Idate){

        //Checking Length
        if(Idate.length() == 10 && Idate.at(2) == '/' && Idate.at(5) == '/' && findComma(Idate)){

            dateOfBirth = Idate;
            return true;

        }else if(Idate.length() == 8 && findComma(Idate)){

            string temp = "";

            for(int i = 0; i < 8; i++){

                //Checking for Numbers
                if(isdigit(Idate.at(i))){
                    temp += Idate.at(i);
                }else{
                    return false;
                }

                if(i + 1 == 2 || i + 1 == 4){
                    temp += '/';
                }

            }

            dateOfBirth = temp;
            return true;

        }else{

            return false;

        }

    }
    bool setSSN(string ISSN){

        //Checking the Length
        if(ISSN.length() == 11 && ISSN.at(3) == '-' && ISSN.at(6) == '-' && findComma(ISSN)){

            SSN = ISSN;
            return true;

        }else if(ISSN.length() == 9 && findComma(ISSN)){

            string temp = "";

            for(int i = 0; i < 9; i++){

                //Checking for Numbers
                if(isdigit(ISSN.at(i))){
                    temp += ISSN.at(i);
                }else{

                    return false;
                }

                if(i + 1 == 3 || i + 1 == 5){
                    temp += '-';
                }

            }

            SSN = temp;
            return true;

        }else{

            return false;

        }



    }
    bool setAddress(string Iaddress){

        int temp = 1;

        //Finding the First Space
        for(int i = 0; i < Iaddress.length(); i++){
            if(Iaddress.at(i) == ' '){
               temp = i;
               break;
            }
        }

        if(!findComma(Iaddress)){
            return false;
        }

        //Checking if the Address Starts with a Street Number
        for(int i = 0; i < temp - 1; i++){
            if(!isdigit(Iaddress.at(i)))
                return false;
        }

        address = Iaddress;
        return true;

    }
    bool setPhoneNumber(string Inumber){

        //Checking the Length
        if(Inumber.length() == 12 && Inumber.at(3) == '-' && Inumber.at(7) == '-' && findComma(Inumber)){

            phoneNumber = Inumber;
            return true;

        }else if(Inumber.length() == 10 && findComma(Inumber)){

            string temp = "";

            //Checking for Numbers
            for(int i = 0; i < 10; i++){

                if(isdigit(Inumber.at(i))){
                    temp += Inumber.at(i);
                }else{

                    return false;
                }

                if(i + 1 == 3 || i + 1 == 6){
                    temp += '-';
                }

            }

            phoneNumber = temp;
            return true;

        }else{

            return false;

        }
    }

    //Interacting With Accounts
    double getAmount(AccountType type) const{
        switch (type) {
            case CHECKING:
                return checking;
            case SAVINGS:
                return saving;
            default:
                return -1;
        }
    }
    bool withdraw(AccountType type, double amount){
        switch (type) {
            case CHECKING:
                if(checking < amount){
                    checking -= amount;
                }else{
                    return false;
                }break;
            case SAVINGS:
                if(saving < amount){
                    saving -= amount;
                }else{
                    return false;
                }break;
            default:
                return false;
        }
        return true;
    }
    bool deposit(AccountType type, double amount){
        switch (type) {
            case CHECKING:
                checking += amount;
                break;
            case SAVINGS:
                saving += amount;
                break;
            default:
                return false;
        }

        //https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        localtime_s(&tstruct,&now);
        strftime(buf, sizeof(buf), "%m/%d/%Y", &tstruct);

        lastDepositDate = buf;

        return true;
    }



private:

    string name;
    string dateOfBirth;
    string SSN;
    string address;
    string phoneNumber;

    double checking;
    double saving;
    string lastDepositDate;

    //finding commas to prevent CSV Corruption
    bool findComma(string Istring){

        for(int i = 0; i < Istring.length(); i++){
            if(Istring.at(i) == ',')
                return false;
        }

        return true;

    }

};