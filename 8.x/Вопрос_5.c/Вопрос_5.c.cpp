#include <iostream>

using namespace std;

template<class T, class U>
T sub(T x, U y) {
	return x - y;
}


int main() {
	cout << sub(3, 2) << '\n';
	cout << sub(3.5, 2) << '\n';
	cout << sub(4, 1.5) << '\n';

	return 0;
}

//Напишите шаблон функции с именем sub, который позволяет пользователю вычитать два значения разных типов