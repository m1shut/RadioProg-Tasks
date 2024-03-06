#include <iostream>
#include <cassert>

using namespace std;

class IntArray {
private:
    int size{0};
    int* arr{nullptr};
public:
    IntArray(int size) {
        this->size = size;
        arr = new int[size]{};
    }
    IntArray(const IntArray& intarray) : size{intarray.size} {
        arr = new int[size];
        
        for (int i{ 0 }; i < size; i++) {
            arr[i] = intarray.arr[i];
        }
    }
    ~IntArray() {
        delete[] arr;
    }
    friend ostream& operator<<(ostream& out, const IntArray& intarray) {
        for (int i{ 0 }; i < intarray.size; i++) {
            out << intarray.arr[i] << ' ';
        }

        return out;
    }
    int& operator[](const int index) {
        assert(index >= 0);

        return arr[index];
    }
    IntArray& operator= (const IntArray& intarray) {
        if (this == &intarray)
            return *this;

        delete[] arr;

        size = intarray.size;
        arr = new int[size];

        for (int i{ 0 }; i < size; i++) {
            arr[i] = intarray.arr[i];
        }

        return *this;
    }
};


IntArray fillArray() {
    IntArray a(5);

    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;

    return a;
}

int main() {
    IntArray a{ fillArray() };
    cout << a << '\n';

    auto& ref{ a }; // используем эту ссылку, чтобы избежать
    // ошибок компиляции, связанных с самоприсваиванием
    a = ref;

    IntArray b(1);
    b = a;

    cout << b << '\n';

    return 0;
}