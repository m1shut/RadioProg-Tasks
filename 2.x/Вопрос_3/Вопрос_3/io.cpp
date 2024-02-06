#include <iostream>
#include "io.h"

using namespace std;

int readNumber() {
    cout << "Enter an integer: ";
    int num;
    cin >> num;

    return num;
}

void writeAnswer(int result) {
    cout << "The answer is " << result << "\n";
}