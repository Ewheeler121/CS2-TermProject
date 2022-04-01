#include "Customer.h"
#include <ctime>

using namespace std;

Customer::Customer(){

    name = "NULL";
    dateOfBirth = "00/00/0000";
    SSN = "000-00-0000";
    address = "000 NULL";
    phoneNumber = "000-000-0000";

    checking = 0;
    saving = 0;
    lastDepositDate = "00/00/0000";

}

bool Customer::findComma(string Istring){

    //Checking for ',' and returns results
    for(char i : Istring){
        if(i == ',')
            return false;
    }

    return true;

}

bool Customer::readCSV(string ICSV){
    int pastComma = 0;
    int marker = 0;
    string result = "";

    //Main Loop
    for(int i = 0; i < ICSV.length(); i++){

        //Finding the ','
        if(ICSV.at(i) == ',' || i + 1 == ICSV.length()){
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
                    result += ICSV.at(ICSV.length() - 1);
                    lastDepositDate = result;
                    marker++;
                    break;
                default:
                    break;
            }
            //restarting results
            result = "";
        }
    }
    return true;
}

string Customer::getCSV(){
    string result = "";

    //making the string that represents the customer in CSV format
    result += name + ',' + dateOfBirth + ',' + SSN + ',' + address + ',' + phoneNumber + ',' + to_string(saving) + ',' +
              to_string(checking) + ',' + lastDepositDate;

    return result;
}

string Customer::getName() const {return name;}
string Customer::getDateOfBirth() const {return dateOfBirth;}
string Customer::getSSN() const {return SSN;}
string Customer::getAddress() const {return address;}
string Customer::getPhoneNumber() const {return phoneNumber;}
string Customer::getLastDeposit() const {return lastDepositDate;}

bool Customer::setName(string Iname){

    //Sets the name, no need for many checks
    if(findComma(Iname)){
        name = Iname;
        return true;
    }else{
        return false;
    }
}

bool Customer::setDateOfBirth(string Idate){

    //Checking Length for format with and without '/'
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

bool Customer::setSSN(string ISSN){

    //Checking Length for format with and without '-'
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

bool Customer::setAddress(string Iaddress){

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

bool Customer::setPhoneNumber(string Inumber){

    //Checking Length for format with and without '-'
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

double Customer::getAmount(AccountType type) const{
    switch (type) {
        case CHECKING:
            return checking;
        case SAVINGS:
            return saving;
        default:
            return -1;
    }
}

bool Customer::withdraw(AccountType type, double amount){
    switch (type) {
        case CHECKING:
            if(amount <= checking){
                checking -= amount;
            }else{
                return false;
            }break;
        case SAVINGS:
            if(amount <= saving){
                saving -= amount;
            }else{
                return false;
            }break;
        default:
            return false;
    }
    return true;
}

bool Customer::deposit(AccountType type, double amount){
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
    //finding the current date
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    localtime_s(&tstruct,&now);
    strftime(buf, sizeof(buf), "%m/%d/%Y", &tstruct);

    lastDepositDate = buf;

    return true;
}