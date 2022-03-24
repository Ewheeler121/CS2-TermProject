#pragma once
#include <string>

using namespace std;

///@enum Contains the type of account
enum AccountType{
    ///Checking account
    CHECKING,
    ///Savings account
    SAVINGS
};

class Customer{
public:

    ///Constructor, Set all variables to Null-like references
    Customer();

    /**Receives a line in a CSV format and set the data to
     * the respective variable
     * @param string in a CSV format
     * @return  true if success, false if failed*/
    bool readCSV(string);

    ///@return All the variables in a CSV format
    string getCSV();

    ///@return Customer's Name
    string getName() const;
    ///@return Customer's Date of Birth
    string getDateOfBirth() const;
    ///@return Customer's SSN Number
    string getSSN() const;
    ///@return Customer's Address
    string getAddress() const;
    ///@return Customer's Phone Number
    string getPhoneNumber() const;
    ///@return The Date of the Customers last Deposit
    string getLastDeposit() const;

    /**Checks if the new name is usable and sets it
     * @param New Name
     * @return True if success, False if failed*/
    bool setName(string);
    /**Checks if the new Date of Birth is usable sets it
     * @param New Date of Birth
     * @return True if success, False if failed*/
    bool setDateOfBirth(string);
    /**Checks if the new SSN Number is usable and sets it
     * @param New SSN Number
     * @return True if success, False if failed*/
    bool setSSN(string);
    /**Checks if the new Address is usable and sets it
     * @param New Address
     * @return True if success, False if failed*/
    bool setAddress(string);
    /**Checks if the new Phone Number is usable and sets it
     * @param New Phone Number
     * @return True if success, False if failed*/
    bool setPhoneNumber(string);

    /**Returns amount in requested account
     * @param Account Type
     * @return Account amount*/
    double getAmount(AccountType) const;
    /**Withdraw from the requested account
     * @param Account type and amount to withdraw
     * @return True if success, False if failed*/
    bool withdraw(AccountType, double);
    /**Deposits amount to requested account and sets
     * LastDepositDate to the current date
     * @param Account type and amount to deposit
     * @return True if success, False if failed*/
    bool deposit(AccountType, double);

private:

    string name; ///< Customer's Name
    string dateOfBirth; ///< Customer's Date of Birth
    string SSN; ///< Customer's SSN Number
    string address; ///< Customer's Address
    string phoneNumber; ///< Customer's Phone Number

    double checking; ///< Customer's Checking account
    double saving; ///< Customer's Savings account
    string lastDepositDate; ///< The Date of the Customers last Deposit

    /**
      Finds Commas
     @param The string to find ','
     @return False if there is a comma, else returns True
     */
    static bool findComma(string);

};