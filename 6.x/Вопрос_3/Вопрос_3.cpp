#include <iostream>

using namespace std;

bool passOrFail() {
	static int i = 3;
		
	return (--i >= 0);
	
}

int main() {
	cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';

	return 0;
}