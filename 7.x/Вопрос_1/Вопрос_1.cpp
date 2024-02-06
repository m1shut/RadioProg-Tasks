#include <iostream>
#include "constants.h"

using namespace std;

double calculateHeight(double initialHeight, int seconds) {
    double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
    double heightNow{ initialHeight - distanceFallen };

    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

bool calculateAndPrintHeight(double initialHeight, int time) {
    double currentHeight = calculateHeight(initialHeight, time);
    cout << "At " << time << " seconds, the ball is at height: " << currentHeight << "\n";

    return (currentHeight == 0.0);
}

int main() {
    cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    cin >> initialHeight;

    int seconds = 0;
    bool stop = false;

    do {
        stop = calculateAndPrintHeight(initialHeight, seconds++);
    } while (!stop);


    return 0;
}