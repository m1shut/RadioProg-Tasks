#include <iostream>

using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 5;
	int b = 25;

	cout << a << "\n";
	cout << b << "\n";
	
	Swap(a, b);
	cout << "========================" << "\n";

	cout << a << "\n";
	cout << b << "\n";

	return 0;
}
