#include <iostream>

using namespace std;

int main() {
	cout << "Enter a positive number: ";
	int num;
	cin >> num;

	if (num < 0) {
		cout << "Negative number entered.  Making positive.\n";
		num = -num;
	}

	cout << "You entered: " << num;

	return 0;
}


