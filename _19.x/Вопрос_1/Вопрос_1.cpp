#include <iostream>

using namespace std;

template<class T>
class Pair1 {
private:
    T firstNum, secondNum;
public:
    Pair1(const T& firstNum, const T& secondNum) {
        this->firstNum = firstNum;
        this->secondNum = secondNum;
    }

    T first() const { return firstNum; }

    T second() const { return secondNum; }

};

int main() {
    Pair1<int> p1{ 5, 8 };
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2{ 2.3, 4.5 };
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
