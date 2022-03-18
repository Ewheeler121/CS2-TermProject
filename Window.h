#pragma once
#include "Bank.h"


class Window{
public:
    Window(string,int);
    ~Window();
    void start();

private:
    Bank *bank;
    bool menu();

    void newCust();
    void delCust();

};