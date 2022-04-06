#pragma once
#include "Bank/Bank.h"

class Window
{
public:

    /**Constructor for Window
     * @param the CSV File name, Max size of the array*/
	Window(string, int);
	~Window(); ///< Destructor
	void start(); ///< Starts the main loop

private:
	Bank* bank; ///< The Bank
	bool menu(); ///< Prints menu and receives input
	void newCust(); ///< Creates a new customer
	void delCust(); ///< Deletes a customer
	void UpdCustInfo(); ///< Updates a customer's info
	void deposit(); ///< deposit into a account
	void withdrawal(); ///< withdrawal from a account
	void ViewCustInfo(); ///< View a customer's info
	void ListCust(); ///< Lists all current customers
};