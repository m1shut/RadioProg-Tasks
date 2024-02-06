#include <iostream>

using namespace std;
using degrees_t = double;
using radians_t = double;

namespace Constants {
    constexpr double pi = 3.14159;
}

radians_t convertToRadians(double degrees) {
    return degrees * Constants::pi / 180;
}

int main() {
    cout << "Enter a number of degrees: ";
    degrees_t degrees{};
    cin >> degrees;

    radians_t radians = convertToRadians(degrees);
    cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}

