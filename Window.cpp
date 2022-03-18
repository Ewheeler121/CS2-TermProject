#include <iostream>
#include <limits>
#include "Window.h"

using namespace std;

Window::Window(string file,int size) {
    bank = new Bank();
    bank->start(file,size);
}

Window::~Window() {
    bank->stop();
    delete bank;

}

void Window::start(){
    while(menu());
}

bool Window::menu(){

    //Print Menu
    newCust();

    return false;
}

void Window::newCust() {

    Customer newCust;
    bool flag = false;
    string temp;

    //Getting Name
    do{
        system("cls");

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if(flag){
            cout << "Error: could not enter name, try again" << endl;
        }

        cout << "Enter the Name: " << endl;
        getline(cin,temp);

        flag = !newCust.setName(temp);

    }while(flag || cin.fail());

    //Getting BirthDate
    do{
        system("cls");

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if(flag){
            cout << "Error: the entered birthdate is incorrect, try again" << endl;
        }

        cout << "Enter the Date of Birth (00/00/2000) : " << endl;
        getline(cin,temp);

        flag = !newCust.setDateOfBirth(temp);

    }while(flag || cin.fail());

    //Getting SSN Number
    do{
        system("cls");

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if(flag){
            cout << "Error: the entered SSN Number is incorrect, try again" << endl;
        }

        cout << "Enter the SSN Number (000-00-0000) : " << endl;
        getline(cin,temp);

        flag = !newCust.setSSN(temp);

    }while(flag || cin.fail());

    //Getting Address
    do{
        system("cls");

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if(flag){
            cout << "Error: the entered Address is incorrect, try again" << endl;
        }

        cout << "Enter the Address (1234 Street) : " << endl;
        getline(cin,temp);

        flag = !newCust.setAddress(temp);

    }while(flag || cin.fail());

    //Getting Phone Number
    do{
        system("cls");

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if(flag){
            cout << "Error: the entered Phone Number is incorrect, try again" << endl;
        }

        cout << "Enter the Phone Number (000-000-0000) : " << endl;
        getline(cin,temp);

        flag = !newCust.setPhoneNumber(temp);

    }while(flag || cin.fail());

    //adding the Customer to the bank
    bank->addCustomer(newCust);
}