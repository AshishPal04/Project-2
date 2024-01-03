#ifndef RANGER_HPP
#define RANGER_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
using namespace std;

struct Arrows
{
    string type_;
    int quantity_;
};

class Ranger : public Character {
    private:
    vector<Arrows> arrows_;
    vector<string> affinities_;
    bool has_companion_;
    public:
    Ranger();
    Ranger(const string name, const string race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, vector<Arrows> arrows = vector<Arrows>(), vector<string> affinities = vector<string>(), bool has_companion = false);
    bool addArrows(const string& arrows, const int& number);
    vector<Arrows> getArrows() const;
    bool fireArrow(const string& arrows);
    bool addAffinity(const string& affinity);
    vector<string> getAffinities() const;
    void setCompanion(const bool& companion);
    bool getCompanion() const;
};

#endif