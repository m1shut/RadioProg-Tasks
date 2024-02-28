#include <iostream>
#include <array>

using namespace std;

//a)

//b)
class Monster {
public:
    enum class Type {
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampir,
    Zombie,

    max_monsters_types
    };

private:
    Type type;
    string name;
    string roar;
    int health;
public:
    //d)
    Monster(Type type, string name, string roar, int health) {
        this->type = type;
        this->name = name;
        this->roar = roar;
        this->health = health;
    }
    //e)
    string getTypeString(Type& type) {
        switch (type) {
        case Type::Dragon: return "dragon"; break;
        case Type::Goblin: return "goblin"; break;
        case Type::Ogre: return "Ogre"; break;
        case Type::Orc: return "Orc"; break;
        case Type::Skeleton: return  "skeleton"; break;
        case Type::Troll: return "troll"; break;
        case Type::Vampir: return "vampir"; break;
        case Type::Zombie: return "zombie"; break;
        default: cout << "There is no such monster";
        }
    }

    void print() {
        cout << name << " the " << getTypeString(type) << " has " << health << " hit points and says " << roar << '\n';
    }

};

//f)
class MonsterGenerator {
public:
    //g)
    static Monster generateMonster() { 
        //h)
        auto type{ static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monsters_types) - 1)) };
        int health{ getRandomNumber(0, 100) };

        static const array<string, 6> s_names{ "Omen", "Glove", "Fishmalurugu", "Pobogaas", "Burun", "Myo"};
        static const array<string, 6> s_roars{ "ROAR", "argh", "wav", "ogg", "hum", "ahahah" };

        auto name{ s_names[static_cast<size_t>(getRandomNumber(0, s_names.size() - 1))] };
        auto roar{ s_roars[static_cast<size_t>(getRandomNumber(0, s_roars.size() - 1))] };
        
        
        return { type, name, roar, health };
    }

    static int getRandomNumber(int min, int max) {
        static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
       
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

};
int main() {
    srand(time(NULL));
    
    //srand(time(NULL));
    /* Monster skeleton{ Monster::Type::Skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();*/

    rand(); 
    Monster m{ MonsterGenerator::generateMonster() };
    m.print();

    

  

    return 0;
}

