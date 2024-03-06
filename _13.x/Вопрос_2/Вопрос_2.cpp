#include <iostream>

using namespace std;

class Average {
private:
    int_least32_t sum{0};
    int_least8_t numbersSee{0};
public:
    Average() {
    }
    Average& operator+=(int num) {
        sum += num;

        numbersSee++;
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Average average) {
        out << (double)average.sum / average.numbersSee;
        return out;
    }
};

int main() {
    Average avg{};

    avg += 4;
    cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10; // два вызова объединены в цепочку
    cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    cout << copy << '\n';

    return 0;
}


