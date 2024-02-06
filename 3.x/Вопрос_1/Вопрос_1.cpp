#include <iostream>

using namespace std;

int readNumber(int x) {
	cout << "Please enter a number: ";
	cin >> x;
	return x;
}

void writeAnswer(int x) {
	cout << "The sum is:" << x;
}

int main() {
	int x;
	
	x = readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}