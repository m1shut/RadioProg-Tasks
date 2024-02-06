#include <iostream>

using namespace std;

template<class T>
T add(T x, T y) {
	return x + y;
}


int main() {
	cout << add(2, 3) << '\n';
	cout << add(1.2, 3.4) << '\n';

	return 0;
}

//Напишите шаблон функции с именем add, который позволяет пользователям складывать 2 значения одного типа.