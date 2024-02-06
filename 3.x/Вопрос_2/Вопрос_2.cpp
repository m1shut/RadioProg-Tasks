#include <iostream>

using namespace std;

int readNumber() {
	int x;
	cout << "Please enter a number:";
	cin >> x;
	
	return x;
}

void writeAnswer(int x) {
	cout << "The quotient is:" << x;
}

int main() {
	int x;
	int y;
	
	x = readNumber();
	y = readNumber();
	writeAnswer(x / y);

	return 0;
}