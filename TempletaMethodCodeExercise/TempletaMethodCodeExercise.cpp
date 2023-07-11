#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct Creature
{
    int attack, health;

    Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
    vector<Creature> creatures;

    CardGame(const vector<Creature>& creatures) : creatures(creatures) {}

    // return the index of the creature that won (is a live)
    // example:
    // - creature1 alive, creature2 dead, return creature1
    // - creature1 dead, creature2 alive, return creature2
    // - no clear winner: return -1
    int combat(int creature1, int creature2)
    {
        hit(creatures[creature1], creatures[creature2]);
        hit(creatures[creature2], creatures[creature1]);

        if (creatures[creature1].health <= 0 && creatures[creature2].health > 0)
        {
            return creature2;
        }
        else if (creatures[creature1].health > 0 && creatures[creature2].health <= 0)
        {
            return creature1;
        }
        else
        {
            return -1;
        }
    }

    virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const vector<Creature>& creatures) : CardGame(creatures) {}

    void hit(Creature& attacker, Creature& other) override {
        
        if (other.health > attacker.attack) return;

        other.health -= attacker.attack;

    }
};

struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const vector<Creature>& creatures) : CardGame(creatures) {}

    void hit(Creature& attacker, Creature& other) override
    {
        other.health -= attacker.attack;
    }
};

int main() 
{
    Creature c0{ 1,1 };
    Creature c1{ 2,2 };
    Creature c2{ 3,3 };
    Creature c3{ 4,4 };
    Creature c4{ 1,10 };

    vector<Creature> Creatures{ c0,c1,c2,c3,c4};
    
    TemporaryCardDamageGame TCDG{Creatures};
    PermanentCardDamageGame PCDG{ Creatures };

    int winner1 = TCDG.combat(0, 1); // 1
    int winner2 = TCDG.combat(2, 3); // 3
    int winner3 = TCDG.combat(1, 3); // 3 || No Winner
    int winner4 = TCDG.combat(0, 4); // 4

    int winner5 = PCDG.combat(0, 1); // 1
    int winner6 = PCDG.combat(2, 3); // 3
    int winner7 = PCDG.combat(1, 3); // No Winner
    int winner8 = PCDG.combat(0, 4); // 4

    cout << winner1 << endl;
    cout << winner2 << endl;
    cout << winner3 << endl;
    cout << winner4 << endl;
    cout << winner5 << endl;
    cout << winner6 << endl;
    cout << winner7 << endl;
    cout << winner8 << endl;
}