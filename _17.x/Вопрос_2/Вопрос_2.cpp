#include <iostream>

using namespace std;

class Fruit {
private:
    string color;
    string name;
public:
    Fruit(const string& color, const string& name) {
        this->color = color;
        this->name = name;
    }
    const string getName() const { return name; }
    const string getColor() const { return color; }
};

class Apple : public Fruit {
protected:
    Apple(const string& color, const string& name) : Fruit{color, name} {}
public:
    Apple(const string& color) : Fruit{color, "apple"} {}
};

class Banana : public Fruit {
public:
    Banana() : Fruit{ "yellow", "banana"} {}
};

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple("granny smith apple", "green") {}

};

int main() {
    Apple a{ "red" };
    Banana b{};
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}


