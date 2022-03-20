#include <iostream>
#include <limits>
#include "Window.h"
using namespace std;

//TODO the GUI more presentable (center, Make the prompts standardized AKA: should look the same)
//TODO in general the prompt when a incorrect input is found is really messy or not existent

Window::Window(string file, int size)
{
    bank = new Bank;
    bank->start(file, size);
}

Window::~Window()
{
    bank->stop();
    delete bank;
}

void Window::start()
{
    while (menu());
}

bool Window::menu()
{
    int choice;

        do {
            system("cls");

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Please try again\n";
            }

            cout << "Lawrence Tech Employee Credit Union" << endl
                 << "******Welcome to the Main Menu******" << endl << endl;
            cout << "1. Create a new checking account." << endl
                 << "2. Remove an existing account." << endl
                 << "3. Update name, address information for an existing customer." << endl
                 << "4. Deposit Transaction." << endl
                 << "5. withdrawl Transaction." << endl
                 << "6. List information of an existing customer." << endl
                 << "7. List customers." << endl
                 << "8. Exit Program." << endl << endl;

            cout << "Enter Choice: ";
            cin >> choice;

            //when you use cin and getline it often results in skipping steps
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (choice < 1 || choice > 8 || cin.fail());

        switch (choice) {
            case 1:
                newCust();
                break;
            case 2:
                delCust();
                break;
            case 3:
                UpdCustInfo();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdrawl();
                break;
            case 6:
                ViewCustInfo();
                break;
            case 7:
                ListCust();
                break;
            case 8:
                return false;
        }

    return true;
}

void Window::newCust() {

    Customer newCust;
    bool flag = false;
    string temp;

    //Getting Name
    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if (flag) {
            cout << "Error: could not enter name, try again" << endl;
        }

        cout << "Enter the Name: " << endl;
        getline(cin, temp);

        flag = !newCust.setName(temp);

    } while (flag || cin.fail());

    //Getting BirthDate
    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if (flag) {
            cout << "Error: the entered birthdate is incorrect, try again" << endl;
        }

        cout << "Enter the Date of Birth (00/00/2000) : " << endl;
        getline(cin, temp);

        flag = !newCust.setDateOfBirth(temp);

    } while (flag || cin.fail());

    //Getting SSN Number
    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if (flag) {
            cout << "Error: the entered SSN Number is incorrect, try again" << endl;
        }

        cout << "Enter the SSN Number (000-00-0000) : " << endl;
        getline(cin, temp);

        flag = !newCust.setSSN(temp);

    } while (flag || cin.fail());

    //Getting Address
    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if (flag) {
            cout << "Error: the entered Address is incorrect, try again" << endl;
        }

        cout << "Enter the Address (1234 Street) : " << endl;
        getline(cin, temp);

        flag = !newCust.setAddress(temp);

    } while (flag || cin.fail());

    //Getting Phone Number
    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if (flag) {
            cout << "Error: the entered Phone Number is incorrect, try again" << endl;
        }

        cout << "Enter the Phone Number (000-000-0000) : " << endl;
        getline(cin, temp);

        flag = !newCust.setPhoneNumber(temp);

    } while (flag || cin.fail());

    //adding the Customer to the bank
    bank->addCustomer(newCust);
}

void Window::delCust()
{

    bool flag = true;
    string temp;

    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if (flag) {
            cout << "Error: could find the enter name, try again" << endl;
        }

        cout << "Enter the Name (type CANCEL to cancel): " << endl;
        getline(cin, temp);

        if (temp == "CANCEL")
            break;

        flag = !bank->delCustomer(temp);

    } while (flag || cin.fail());
}

void Window::UpdCustInfo()
{
    int c;
    string temp;
    bool flag;
    Customer* ptr;

    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        cout << "Enter the name of the customer, or enter 'CANCEL' to cancel: ";
        getline(cin,temp);

        if (temp == "CANCEL")
            break;

        ptr = bank->getCustomer(temp);

        if (ptr == nullptr) {
            flag = true;
        }
        else{

            flag = false;
            cout << "What would you like to modify?\n"
                 << "1. Name\n" << "2. Address\n" << "3. Phone Number\n";
            cin >> c;

            //when you use cin and getline it often results in skipping steps
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (c) {
                case 1:
                    cout << "Enter new Name: ";
                    getline(cin, temp);
                    ptr->setName(temp);
                    break;
                case 2:
                    cout << "Enter new Address (1234 Street):";
                    getline(cin, temp);
                    ptr->setAddress(temp);
                    break;
                case 3:
                    cout << "Enter new Phone Number (000-000-0000): ";
                    getline(cin, temp);
                    ptr->setPhoneNumber(temp);
                    break;
                default:
                    flag = true;
            }
        }
    }while (cin.fail() || flag);

}

//TODO redo the checks, its really messy rn and does not allow to use amounts in prompts
void Window::deposit(){

    Customer *ptr;
    bool flag;
    string temp;
    int accountType;
    double amount;

    do{
        system("cls");
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        cout << "Enter the Name of the Customer, or enter 'CANCEL' to cancel: " << endl;
        getline(cin,temp);

        if (temp == "CANCEL")
            break;

        ptr = bank->getCustomer(temp);

        if(ptr == nullptr){
            flag = true;
        }
        else{
            flag = false;
        }
    }while(cin.fail() || flag);

    do {

        system("cls");
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        if(flag){
            cout << "Enter 1 or 2" << endl;
        }

        cout << "1. Savings\n2. Checking\n";
        cin >> accountType;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        cout << "Enter how much to Deposit: " << endl;
        cin >> amount;

        switch (accountType) {
            case 1:
                flag = !ptr->deposit(SAVINGS, amount);
                break;
            case 2:
                flag = !ptr->deposit(CHECKING, amount);
                break;
            default:
                flag = true;
                break;
        }

    }while(cin.fail() || flag);
}

//TODO redo the checks, its really messy rn and does not allow to use amounts in prompts
void Window::withdrawl()
{
    Customer* ptr;
    bool flag;
    string temp;
    int accountType;
    double amount;

    do {
        system("cls");

        cout << "Enter the Name of the Customer, or enter 'CANCEL' to cancel: " << endl;
        getline(cin, temp);

        if (temp == "CANCEL")
            break;

        ptr = bank->getCustomer(temp);

        if (ptr == nullptr) {
            flag = true;
        }
        else {
            flag = false;
        }
    } while (flag);

    do {
        system("cls");
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        do {
            system("cls");

            cout << "1. Savings\n2. Checking\n";
            cin >> accountType;

            if (flag)
            {
                cout << "Error: Not enough funds to withdraw requested amount.\n";
            }

            cout << "Enter how much to Withdraw: " << endl;
            cin >> amount;

            switch (accountType) {
                case 1:
                    flag = !ptr->withdraw(SAVINGS, amount);
                    break;
                case 2:
                    flag = !ptr->withdraw(CHECKING, amount);
                    break;
                default:
                    flag = true;
                    break;
            }
        } while (flag);
    } while (cin.fail());
}

//TODO needs to be cleaned up and add more checking in inputs
void Window::ViewCustInfo()
{
    Customer* ptr;
    bool flag;
    string temp;

    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        cout << "Enter the Name of the Customer, or enter 'CANCEL' to cancel: " << endl;
        getline(cin, temp);

        if (temp == "CANCEL")
            break;

        ptr = bank->getCustomer(temp);

        if (ptr == nullptr) {
            flag = true;
        }
        else {
            flag = false;
        }
    } while (cin.fail() || flag);

    if (temp != "CANCEL") {
    system("cls");
    cout << "Information for " << temp << endl
         << "Name: " << ptr->getName() << endl
         << "Date of Birth: " << ptr->getDateOfBirth() << endl
         << "SSN: " << ptr->getSSN() << endl
         << "Address: " << ptr->getAddress() << endl
         << "Phone Number: " << ptr->getPhoneNumber() << endl
         << "Savings: " << ptr->getAmount(SAVINGS) << endl
         << "Checking: " << ptr->getAmount(CHECKING) << endl
         << "Last Deposit Date: " << ptr->getLastDeposit() << endl;
    }

    system("pause");
}

void Window::ListCust()
{
    Customer* ptr = bank->getCustomer(0);
    int count = 0;

    cout << "List of Customers:\n";

    // Loop for all customers in system
    while(ptr != nullptr){

        cout << "Name: " << ptr->getName() << ", SSN: " << ptr->getSSN() << endl;

        count++;
        ptr = bank->getCustomer(count);
    }

    system("pause");
}