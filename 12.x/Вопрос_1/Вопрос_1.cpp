#include <iostream>
#include <cmath>

using namespace std;

//a)
class Point2d {
private:
    double m_x;
    double m_y;
public:
    Point2d(double m_x = 0, double m_y = 0) {
        this->m_x = m_x;
        this->m_y = m_y;
    }

    void print() {
        cout << "Point2d(" << m_x << ", " << m_y << ")" << '\n';
    }

    //b)
    int distanceTo(const Point2d& point) {
        return sqrt((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y));
    }
    //c)
    friend int distanceFrom(const Point2d& point1, const Point2d& point2);
};

int distanceFrom(const Point2d& point1, const Point2d& point2) {
    return sqrt((point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) + (point1.m_y - point2.m_y) * (point1.m_y - point2.m_y));
}

int main() {
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
    return 0;
}

