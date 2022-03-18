#pragma once

#include <string>

using namespace std;

enum AccountType{
    CHECKING,
    SAVINGS
};

class Customer{
public:

    //constructor
    Customer();

    //CSV management
    bool readCSV(string);
    string getCSV();

    //Getters
    string getName() const;
    string getDateOfBirth() const;
    string getSSN() const;
    string getAddress() const;
    string getPhoneNumber() const;
    string getLastDeposit() const;

    //Setters
    bool setName(string);
    bool setDateOfBirth(string);
    bool setSSN(string);
    bool setAddress(string);
    bool setPhoneNumber(string);

    //Account Interaction
    double getAmount(AccountType) const;
    bool withdraw(AccountType, double);
    bool deposit(AccountType, double);

private:

    string name;
    string dateOfBirth;
    string SSN;
    string address;
    string phoneNumber;

    double checking;
    double saving;
    string lastDepositDate;

    //finds Commas
    bool findComma(string);

};