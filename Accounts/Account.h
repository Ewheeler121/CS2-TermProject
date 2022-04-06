#pragma once

///@enum Contains the type of account
enum AccountType{
    ///Checking account
    CHECKING,
    ///Savings account
    SAVINGS,
    ///Current Amount of Account Types
    COUNT = 2
};

class Account{
protected:

    double amount = 0;///< the amount of money in the account
public:

    double getAmount() const; ///< @return the amount in account
    /**attempts to withdraw from the account
     * @param the amount you wish to withdrawal
     * @return true if success, false if failed*/
    bool withdrawal(double);
    /**attempts to deposit from the account
     * @param the amount you wish to deposit
     * @return true if success, false if failed*/
    bool deposit(double);
    /**Used to set amount during CSV input
     * @param amount of money*/
    void setAmount(double);

};
