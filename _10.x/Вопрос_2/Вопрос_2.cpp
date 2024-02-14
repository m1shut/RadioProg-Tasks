#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Base {
	string name;
	int rate;
};

int getNumStudents(){
	int size;
	cout << "How many student do you want to enter? ";
	cin >> size;

	return size;
}

vector<Base> getNameAndRateStudents() {
	int studentsNum = getNumStudents();
	
	vector <Base> stud(static_cast<vector<Base>::size_type>(studentsNum));

	for (auto& student : stud) {
		cout << "Enter a student name: ";
		cin >> student.name;

		cout << "Enter a rate of student: ";
		cin >> student.rate;
	}

	return stud;
}

bool studComapre(Base& a, Base& b) {
	return a.rate > b.rate;
}

int main() {
	auto stud = getNameAndRateStudents();

	sort(stud.begin(), stud.end(), studComapre);

	for (auto& student : stud) {
		cout << student.name << " got a grade of " << student.rate << "\n";
	}

	return 0;
}


