#include <iostream>
#include <limits>
#include "Window.h"
using namespace std;

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
    } while (true);
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

        if (flag == false) {
            cout << "Error: could find the enter name, try again" << endl;
        }

        cout << "Enter the Name: " << endl;
        getline(cin, temp);

        if (temp == "CANCEL")
            break;

        flag = bank->delCustomer(temp);

    } while (flag || cin.fail() || flag);
}

void Window::UpdCustInfo()
{
    int c;
    string temp;
    bool flag = true;
    Customer* ptr;

    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        cout << "Enter the name of the customer you wish to update, or enter 'CANCEL' to cancel: ";
        cin >> temp;

        if (temp == "CANCEL")
            break;

        ptr = bank->getCustomer(temp);

        if (ptr == nullptr) {
            flag = false;
        }
        else {
            cout << "What would you like to modify?\n"
                 << "1. Name\n" << "2. Address\n" << "3. Phone Number\n";
            cin >> c;

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
            }
        }
    }while (cin.fail() || flag);

}

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

        cout << "Enter the Name of the Customer: " << endl;
        getline(cin,temp);

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

        cout << "1. Savings\n2. Checking\n";
        cin >> accountType;

        cout << "Enter how much to Deposit: " << endl;
        cin >> amount;

        switch (accountType) {
            case 1:
                ptr->deposit(SAVINGS, amount);
                break;
            case 2:
                ptr->deposit(CHECKING, amount);
        }

    }while(cin.fail());
}

void Window::withdrawl()
{
    Customer* ptr;
    bool flag;
    string temp;
    int accountType;
    double amount;

    do {
        system("cls");

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        cout << "Enter the Name of the Customer: " << endl;
        getline(cin, temp);

        ptr = bank->getCustomer(temp);

        if (ptr == nullptr) {
            flag = true;
        }
        else {
            flag = false;
        }
    } while (cin.fail() || flag);

    flag = true;

    do {
        system("cls");
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: could not get line, try again" << endl;
        }

        cout << "1. Savings\n2. Checking\n";
        cin >> accountType;

        do {
            system("cls");

            if (!flag)
            {
                cout << "Error: Not enough funds to withdraw requested amount.\n";
            }

            cout << "Enter how much to Withdraw: " << endl;
            cin >> amount;

            switch (accountType) {
                case 1:
                    flag = ptr->withdraw(SAVINGS, amount);
                    break;
                case 2:
                    flag = ptr->withdraw(CHECKING, amount);
                    break;
            }
        } while (!flag);
    } while (cin.fail());
}

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

        cout << "Enter the Name of the Customer: " << endl;
        getline(cin, temp);

        ptr = bank->getCustomer(temp);

        if (ptr == nullptr) {
            flag = false;
        }
        else {
            flag = true;
        }
    } while (cin.fail() || flag);

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

void Window::ListCust()
{
    Customer* ptr;
    int x = 100;
    
    cout << "List of Customers:\n";
    // Loop for all customers in system
    for (int i = 0; i < x; i++)
    {
        ptr = bank->getCustomer(i);

        if (ptr == nullptr) {
            break;
        }
        else {
            cout << "Name: " << ptr->getName() << ", SSN: " << ptr->getSSN() << endl;
        }
    }

    system("pause");
}