#ifndef MAGE_HPP
#define MAGE_HPP
#include <iostream>
#include "Character.hpp"
using namespace std;

class Mage : public Character {
    private:
    string school_of_magic_;
    string weapon_;
    bool can_summon_incarnate_;
    public:
    Mage();
    Mage(const string name, const string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const string school = "NONE", const string weapon = "NONE", bool incarnate = false);
    bool setSchool(const string& school);
    string getSchool() const;
    bool setCastingWeapon(const string& weapon);
    string getCastingWeapon() const;
    void setIncarnateSummon(const bool& incarnate);
    bool hasIncarnateSummon() const;
};

#endif