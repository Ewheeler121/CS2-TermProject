#include <iostream>
#include <fstream>
#include "Window.h"


using namespace std;

void readConfig();

string MAINFILE;
int SIZE;

int main() {

    //File Stuff
    MAINFILE = "Bank_Data.csv";
    SIZE = 100;

    //readConfig();

    //Starting the Window
    Window window(MAINFILE,SIZE);
    window.start();

    return 0;
}

void readCONFIG(){

    ifstream config;
    config.open("config.cfg");

    if(config.fail()){
        cout << "ERROR: config.cfg not found" << endl;
        system("pause");
        exit(-1);
    }

    config >> MAINFILE;
    config >> SIZE;
}