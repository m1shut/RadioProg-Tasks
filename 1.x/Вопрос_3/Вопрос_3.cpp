#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    
    cout << "Enter an integer: ";
    cin >> num1;
    cout << "Enter another integer: ";
    cin >> num2;
    cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
    cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";

    return 0;
}