#include "Bank.h"
#include <string>
#include <fstream>

bool Bank::start(string file,int size){

    //setting variables and allocating the array
    Bank::size = size;
    Bank::file = file;
    count = 0;
    customerList = new Customer[size];

    //opening filestream
    ifstream input;
    input.open(file);
    if(input.fail()){
        return false;
    }

    string temp;

    //getting past the titles
    getline(input,temp);

    //Main Loop to get input
    while (!input.eof()){
        getline(input,temp);
        if(customerList[count].readCSV(temp)){
            return false;
        }
        count++;
        if(count == size){
            break;
        }
    }

    count -=1;

    input.close();
    return true;
}

void Bank::stop(){

    //making or replacing the output file
    ofstream output;
    output.open(file,ios::out | ios::trunc);

    output << "Name,Date of Birth,SSN Number,Address,Phone Number,Saving,Checking,Last Deposit Date" << endl;

    for(int i = 0; i < count; i++){
        output << customerList[i].getCSV() << endl;
    }

    delete[] customerList;
    output.close();
}

void swap(Customer *xp, Customer *yp)
{
    Customer temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Bank::sort() {
    int i, j, min_idx;

    for (i = 0; i < count-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < count; j++)
            if (customerList[j].getName() < customerList[min_idx].getName())
                min_idx = j;

        swap(&customerList[min_idx], &customerList[i]);
    }
}

int Bank::binarySearch(int p, int r, string name) {
    if (p <= r) {
        int mid = (p + r)/2;
        if (customerList[mid].getName() == name)
            return mid;
        if (customerList[mid].getName() > name)
            return binarySearch(p, mid - 1, name);
        if (customerList[mid].getName() < name)
            return binarySearch(mid + 1, r, name);
    }
    return -1;
}

bool Bank::addCustomer(Customer customer) {

    if(count + 1 > size){
        return false;
    }

    customerList[count] = customer;
    count++;
    sort();

    return true;
}

Customer* Bank::getCustomer(int index){

    if(index < 0 || index > count - 1){
        return nullptr;
    }
    return &customerList[index];
}

Customer* Bank::getCustomer(string name){
    int temp = binarySearch(0,count - 1,name);
    if(temp == -1)
        return nullptr;
    return &customerList[temp];
}

bool Bank::delCustomer(int index){

    if(index < 0 || index > count - 1){
        return false;
    }

    for(int i = index; i < count;i++){
        customerList[i] = customerList[i + 1];
    }

    count--;
    return true;
}

bool Bank::delCustomer(string name) {
    int temp = binarySearch(0,count - 1,name);
    if(temp == -1)
        return false;
    for(int i = temp; i < count;i++){
        customerList[i] = customerList[i + 1];
    }

    count--;
    return true;
}