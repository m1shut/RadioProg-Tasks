#include <iostream>

using namespace std;

double getNum() {
    double num;
    cout << "Enter a double value: ";
    cin >> num;

    return num;
}

char getOp() {
    char op;
    cout << "Enter one of the following: +, -, *, or /: ";
    cin >> op;

    return op;
}

void printResult(double num1, char op, double num2) {
    switch (op) {
    case '+': cout << num1 << " + " << num2 << " is " << num1 + num2 << "\n"; break;
    case '-': cout << num1 << " - " << num2 << " is " << num1 - num2 << "\n"; break;
    case '*': cout << num1 << " * " << num2 << " is " << num1 * num2 << "\n"; break;
    case '/': cout << num1 << " / " << num2 << " is " << num1 / num2 << "\n"; break;
    }
}

int main() {
    double num1 = getNum();
    double num2 = getNum();
    char op = getOp();

    printResult(num1, op, num2);

    return 0;
}
