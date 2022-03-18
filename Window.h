#pragma once
#include "Bank.h"

class Window
{
public:
	Window(string file, int size);
	~Window();
	void start();

private:
	Bank* bank;
	bool menu();
	void newCust();
	void delCust();
	void UpdCustInfo();
	void deposit();
	void withdrawl();
	void ViewCustInfo();
	void ListCust();
};