#pragma once
#include "Customer.h"

class Bank{

public:

    /**Starts the bank and reads the CSV file
     * @param the CSV File name, Max size of the array
     * @return True if success, false if failed*/
    bool start(string, int);

    ///Stops the bank and writes to the CSV file the new data clean up as well
    void stop();

    /**Adds a customer to the array list, calls sort() after
     * @param The new Customer
     * @return True if success, False if failed*/
    bool addCustomer(Customer);
    /**Deletes the customer in the array list
     * @param Array index location
     * @return True if success, False if failed*/
    bool delCustomer(int);
    /**Deletes the customer in the array list
     * @param Customer's name
     * @return True if success, False if failed*/
    bool delCustomer(string);
    /**Returns the requested customer
     * @param Array index location
     * @return Requested customer*/
    Customer* getCustomer(int);
    /**Returns the requested customer
     * @param Customer's name
     * @return Requested customer*/
    Customer* getCustomer(string);

private:

    int count; ///< Current highest Array index location
    int size; ///< Max size of the Array
    string file; ///< The CSV file name
    Customer* customerList; ///< List of Customers

    /**Search the array for a Customer's name
     * @param Start, Index of highest customer, Customer's Name
     * @return Index location of Customer with the name*/
    int binarySearch(int , int, string);
    void sort(); ///< Sorts the array based on the Customer's Name
};