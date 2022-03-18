#include "Window.h"

using namespace std;

int main() {

    const string MAINFILE = "Bank_Data.csv";
    const int SIZE = 100;

    //Starting the Window
    Window window(MAINFILE,SIZE);
    window.start();

    return 0;
}