#include <iostream>

using namespace std;

enum typeMonster {
	ogre,
	dragon,
	orc,
	giant_spider,
	slime
};

struct Monsters {
	typeMonster type;
	string name;
	int health;
};

string getMonsterType(typeMonster type) {
	switch (type) {
	case typeMonster::ogre: return "Ogre";
	case typeMonster::dragon: return "Dragone";
	case typeMonster::orc: return "Orc";
	case typeMonster::giant_spider: return "Giant spider";
	case typeMonster::slime: return "Slime";
	}

	return "Unknown";
}

void printMonster(Monsters monster) {
	cout << "This " << getMonsterType(monster.type) << " is named " << monster.name << " and has " << monster.health << " health." << "\n";
}

int main() {
    
	Monsters Torg;
	Torg.name = "Torg";
	Torg.health = 145;
	Torg.type = ogre;
	
	Monsters Blurp;
	Blurp.name = "Blurp";
	Blurp.health = 23;
	Blurp.type = slime;

	printMonster(Torg);
	printMonster(Blurp);

	return 0;
}


