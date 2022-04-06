#include "Account.h"

double Account::getAmount() const{
    return amount;
}

void Account::setAmount(double input){
    amount = input;
}

bool Account::withdrawal(double requested){
    if(requested <= amount){
        amount -= requested;
    }else{
        return false;
    }
    return true;
}

bool Account::deposit(double requested){
    amount += requested;
    return true;
}