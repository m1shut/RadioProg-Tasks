#include <iostream>
#include "constants.h"

using namespace std;

double getHeightTower() {
	int heightTower;
	cout << "Enter the height of the tower in meters: ";
	cin >> heightTower;

	return heightTower;
}

double calculateHeight(double towerHeight, int seconds) {
	double distanceFallen = (gravity * (seconds * seconds)) / 2;
	double currentHeight = distanceFallen - towerHeight;

	return currentHeight;
}

void printHeight(double height, int seconds) {
	if (height > 0.0)
		cout << "At " << seconds << " seconds, ball is at height " << " meters" << "\n";
	else
		cout << "At " << seconds << " seconds, the ball is on the ground." << "\n";
}

void calculateAndPrintHeight(double towerHeight, int seconds) {
	double height = calculateHeight(towerHeight, seconds);
	printHeight(height, seconds);
}


int main() {
   
	const double towerHeight = getHeightTower();
		
	calculateAndPrintHeight(towerHeight, 0);
	calculateAndPrintHeight(towerHeight, 1);
	calculateAndPrintHeight(towerHeight, 2);
	calculateAndPrintHeight(towerHeight, 3);
	calculateAndPrintHeight(towerHeight, 4);
	calculateAndPrintHeight(towerHeight, 5);

	return 0;
}
