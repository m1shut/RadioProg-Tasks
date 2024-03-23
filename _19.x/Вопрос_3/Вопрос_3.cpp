#include <iostream>
#include<string>

using namespace std;

template<class T, class V>
class Pair {
private:
    T m_first{};
    V m_second{};
public:
    Pair(const T& firstStr, const V& secondNum) : m_first{ firstStr }, m_second{ secondNum } {}
    
    const T& first() const { return m_first; }
    const V& second() const { return m_second; }
};

template<class V>
class StringValuePair : public Pair<string, V> {
public:
    StringValuePair(const string& str, const V& num) : Pair<string, V> { str, num } {};

};

int main() {
    StringValuePair<int> svp{ "Hello", 5 };
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}

