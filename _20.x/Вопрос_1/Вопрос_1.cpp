#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction {
private:
    int denominator;
    int numerator;
public:
    Fraction(int denominator, int numerator) {
        this->denominator = denominator;
        this->numerator = numerator;
        
        if (denominator == 0) throw runtime_error("Invalid denominator");
    }
};

int main() {
    cout << "Enter the numerator: ";
    int numerator;
    cin >> numerator;

    cout << "Enter the denominator: ";
    int denominator;
    cin >> denominator;

    try {
        Fraction f(denominator, numerator);
        cout << "Answer: " << numerator / denominator;
    }
    catch (exception ex) {
        cout << ex.what();
    }

    return 0;
}


