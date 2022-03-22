#include "Bank.h"
#include <string>
#include <fstream>

//Starting and Stopping
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

    //Main Loop to get Customer Info
    while (!input.eof()){
        getline(input,temp);
        if(!customerList[count].readCSV(temp)){
            return false;
        }
        count++;
        if(count == size){
            break;
        }
    }

    count -= 1;

    input.close();
    return true;
}

void Bank::stop(){

    //making or replacing the output file
    ofstream output;
    output.open(file,ios::out | ios::trunc);

    //printing titles
    output << "Name,Date of Birth,SSN Number,Address,Phone Number,Saving,Checking,Last Deposit Date" << endl;

    //printing CSV formatted info
    if(count == 0 && customerList[0].getName() != "NULL"){
        output << customerList[0].getCSV() << endl;
    }else{
        for(int i = 0; i < count; i++){
            output << customerList[i].getCSV() << endl;
        }
    }

    delete[] customerList;
    output.close();
}

//Basic swap for sorting
void swap(Customer *xp, Customer *yp)
{
    Customer temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Search and Sorting
void Bank::sort() {
    int i, j, min_idx;

    for (i = 0; i < count; i++)
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

//Adding Customers into the main Array
bool Bank::addCustomer(Customer customer) {

    //Checks if the size limit has been reached
    if(count + 1 > size){
        return false;
    }

    //adding to list of Customers
    customerList[count] = customer;
    count++;

    //Sorting the Array
    sort();
    return true;
}

//Searching for the customer and returning a pointer to it
Customer* Bank::getCustomer(int index){

    //Checking if the index is within Range
    if(count == 1 && index == 0){
     return &customerList[0];
    }if(index < 0 || index > count - 1){
        return nullptr;
    }
    return &customerList[index];
}

Customer* Bank::getCustomer(string name){

    //Searching for the Name and returns results
    int temp = binarySearch(0,count,name);
    if(temp == -1)
        return nullptr;
    return &customerList[temp];
}

//Searches for a customer to delete and return the result
bool Bank::delCustomer(int index){

    //Checking if the index is within Range
    if(index < 0 || index > count - 1){
        return false;
    }

    //Moving the customer up one to replace the deleted customer
    for(int i = index; i < count;i++){
        customerList[i] = customerList[i + 1];
    }

    //changing the count of the array
    count--;
    return true;
}

bool Bank::delCustomer(string name) {

    //Searching the Array
    int temp = binarySearch(0,count - 1,name);
    if(temp == -1)
        return false;

    //Moving the customer up one to replace the deleted customer
    for(int i = temp; i < count;i++){
        customerList[i] = customerList[i + 1];
    }

    count--;
    return true;
}