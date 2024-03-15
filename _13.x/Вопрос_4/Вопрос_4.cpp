#include <iostream>
#include <cmath>

using namespace std;

//b)
class FixedPoint2 {
private:
    int_least16_t m_wholePart{ };
    int_least8_t m_fractionalPart{ };
public:
    FixedPoint2(double num)
        :m_wholePart{ static_cast<int_least16_t>(round(num * 100) / 100) }, 
        m_fractionalPart{ static_cast<int_least8_t>(round(num * 100) - m_wholePart * 100) }
    {
    }

    FixedPoint2(int_least16_t wholePart = 0, int fractionalPart = 0) 
        : m_wholePart{ wholePart }, m_fractionalPart{ static_cast<int_least8_t>(fractionalPart) }
    {
         if (m_fractionalPart > 99 || m_fractionalPart < -99) {
            if(m_fractionalPart > 99)
                m_fractionalPart /= 10;
            
            if (m_fractionalPart < -99)
                m_fractionalPart = -m_fractionalPart;
        }
        
         if (m_wholePart < 0 || m_fractionalPart < 0) {
             if (m_wholePart > 0)
                m_wholePart = -m_wholePart;
            
            if (m_fractionalPart > 0)
                m_fractionalPart = -m_fractionalPart;
        }
    }

    //c)
    operator double() const {
        return m_wholePart + static_cast<double>(m_fractionalPart) / 100.0;
    }
    friend bool operator==(const FixedPoint2& fx1, FixedPoint2& fx2);
    
    //d)
    FixedPoint2 operator-() {
        return { static_cast<int_least16_t>(-m_wholePart), static_cast<int_least8_t>(-m_fractionalPart) };
    }
};
    ostream& operator<<(ostream& out, FixedPoint2& point) {
        out << static_cast<double>(point);
        return out;
    }
    bool operator==(const FixedPoint2& fx1, FixedPoint2& fx2) {
        return (fx1.m_wholePart == fx2.m_wholePart && fx1.m_fractionalPart == fx2.m_fractionalPart);
    }
    istream& operator>>(istream& in, FixedPoint2& fx) {
        double num;
        in >> num;
        fx = FixedPoint2{num};
        return in;
    }
    FixedPoint2 operator+(const FixedPoint2& fx1, const FixedPoint2& fx2) {
        return { static_cast<double>(fx1) + static_cast<double>(fx2) };
    }
    

void testAddition() {
    cout << boolalpha;
        // оба положительные, без переполнения дробной части
    cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n';
        // оба положительные, с переполнением дробной части
    cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n';
        // оба отрицательные, без переполнения дробной части
    cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n';
        // оба отрицательные, с переполнением дробной части
    cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n';
        // второе отрицательное, без переполнения дробной части
    cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n';
        // второе отрицательное, возможно переполнение дробной части
    cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n';
        // первое отрицательное, без переполнения дробной части
    cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n';
        // первое отрицательное, возможно переполнение дробной части
    cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n';
    }

int main() {
    testAddition();

    FixedPoint2 a{ -0.48 };
    std::cout << a << '\n';

    std::cout << -a << '\n';

    std::cout << "Enter a number: "; // введите 5.678
    std::cin >> a;

    std::cout << "You entered: " << a << '\n';

    return 0;
}