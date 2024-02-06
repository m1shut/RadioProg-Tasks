#include <iostream>

using namespace std;

template<class T, class U>

auto mult(T x, U y) {
	return x * y;
}

int main() {
	cout << mult(2, 3) << '\n';
	cout << mult(1.2, 3) << '\n';

	return 0;
}
//Напишите шаблон функции с именем mult, который позволяет пользователю умножать одно значение любого типа на число int.