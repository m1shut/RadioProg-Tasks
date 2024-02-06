#include <iostream>

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

int main() {
    int x = readNumber();
    int y = readNumber();

    writeAnswer(x + y);

    return 0;
}