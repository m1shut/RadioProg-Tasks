#include <iostream>

using namespace std;

void printText(const char* str) {
	while (*str != '\0') {
		cout << *str++;
	}
}

int main() {
	printText("Hello, world!");

	return 0;
}

