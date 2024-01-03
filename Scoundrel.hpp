#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP
#include <iostream>
#include <string>
#include <cctype>
#include "Character.hpp"
using namespace std;

enum Dagger {WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE};

class Scoundrel : public Character {
    private:
    Dagger dagger_;
    string faction_;
    bool has_disguise_;
    public:
    Scoundrel();
    Scoundrel(const string name, const string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false,const string dagger = "NONE", const string faction = "NONE", bool disguise = false);
    void setDagger(const string& dagger);
    string getDagger() const;
    bool setFaction(const string& faction);
    string getFaction() const;
    void setDisguise(const bool& disguise);
    bool hasDisguise() const;
};

#endif