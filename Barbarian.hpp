#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <iostream>
#include "Character.hpp"
using namespace std;

class Barbarian : public Character{
    private:
    string main_weapon_;
    string secondary_weapon_;
    bool enraged_;
    public:
    Barbarian();
    Barbarian(const string name, const string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const string main_weapon = "NONE", const string secondary_weapon = "NONE", bool enraged = false);
    bool setMainWeapon(const string& main_weapon);
    string getMainWeapon() const;
    bool setSecondaryWeapon(const string& secondary_weapon);
    string getSecondaryWeapon() const;
    void setEnrage(const bool& enraged);
    bool getEnrage() const;
    void toggleEnrage();
};

#endif