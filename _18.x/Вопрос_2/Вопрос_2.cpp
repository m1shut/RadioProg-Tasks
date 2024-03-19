#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
private:
    int m_x{};
    int m_y{};
    int m_z{};

public:
    Point(int x, int y, int z)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {

    }

    friend ostream& operator<<(ostream& out, const Point& p) {
        return out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ')';
    }
};

//2a)   
class Shape {
private:


public:
    virtual ostream& print(ostream& out) const = 0;

    friend ostream& operator<<(ostream& out, const Shape& shape) {
        return shape.print(out);
    }
    virtual ~Shape() = default;
};

//2b)
class Triangle : public Shape {
private:
    Point a;
    Point b;
    Point c;
public:
    Triangle(const Point& a, const Point& b, const Point& c) : a{ a }, b{ b }, c{ c } {
    }
    ostream& print(ostream& out) const override {
        out << "Triangle(" << a << ", " << b << ", " << c << ")";
        return out;
    }
};

class Circle : public Shape {
private:
    Point center;
    int radius{};
public:
    Circle(const Point& center, int radius) : center{ center }, radius{radius} {
    }
    ostream& print(ostream& out) const override{
        out << "Circle(" << center << ", raduis " << radius << ")";
        return out;
    }

    int getRadius() const { return radius; }
};

//2c)
int getLargestRadius(const vector<Shape*>& vs) {
    int maxRaduis{ 0 };

    for (const auto* el : vs) {
        if (auto* c{ dynamic_cast<const Circle*>(el) }) {
            maxRaduis = max(maxRaduis, c->getRadius());
        }
    }
    return maxRaduis;
}

int main() {
    vector<Shape*> v{
       new Circle{Point{1, 2, 3}, 7},
       new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
       new Circle{Point{4, 5, 6}, 3}
    };

    for (const auto* el : v) {
        cout << *el << '\n';
    }

    cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    for (const auto* el : v) {
        delete el;
    }

    return 0;
}


