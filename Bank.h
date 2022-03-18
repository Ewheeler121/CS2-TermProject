#pragma once
#include "Customer.h"

class Bank{

public:

    //Start and Stop
    bool start(string,int);
    void stop();

    //List Managing
    void sort();
    bool addCustomer(Customer);
    bool delCustomer(int);
    bool delCustomer(string);
    Customer* getCustomer(int);
    Customer* getCustomer(string);

private:

    int count;
    int size;
    string file;
    Customer* customerList;


    int binarySearch(int , int, string);
};