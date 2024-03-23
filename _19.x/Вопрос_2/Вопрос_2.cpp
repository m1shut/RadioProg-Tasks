#include <iostream>

using namespace std;

template <class T, class V>
class Pair {
private:
    T firstNum;
    V secondNum;
public:
    Pair(const T& firstNum, const V& secondNum) {
        this->firstNum = firstNum;
        this->secondNum = secondNum;
    }

    T& first() const { return firstNum; }
    V& second() const { return secondNum; }
};

int main() {
    Pair<int, double> p1{ 5, 6.7 };
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2{ 2.3, 4 };
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}