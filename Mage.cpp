#include "Mage.hpp"

/**
  Default constructor.
  Default-initializes all private members. 
  Default character name: "NAMELESS". Booleans are default-initialized to False. 
  Default school of magic and weapon: "NONE". 
*/

Mage::Mage()
{
    setName("NAMELESS");
    school_of_magic_ = "NONE";
    weapon_ = "NONE";
    can_summon_incarnate_ = false;
}

/**
  Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false.
  @param      : The character's school of magic (a const string reference). Valid schools: 
                [ELEMENTAL, NECROMANCY, ILLUSION]. 
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the school name is invalid, set it to "NONE"
  @param      : The character's choice of weapon (a const string reference). 
                Valid weapons: [WAND, STAFF]
                String inputs can be in lowercase, but must be converted to 
                uppercase when setting the variable.
                If the weapon is invalid, set it to "NONE"
  @param      : A flag indicating whether the character is able to summon an 
                incarnate. Default to false.
  @post       : The private members are set to the values of the corresponding 
                parameters.
                REMEMBER: If the school of magic or weapon is not provided or invalid, the 
                variables should be set to "NONE". 
*/

Mage::Mage(const string name, const string race, int vitality, int armor, int level, bool enemy, const string school, const string weapon, bool incarnate) : Character(name, race, vitality, armor, level, enemy)
{
    string new_school = "";

    for (int i=0; i<school.length();i++)
    {
        new_school += toupper(school[i]);
    }

    if (new_school == "ELEMENTAL")
    {
        school_of_magic_ = "ELEMENTAL";
    }
    else if (new_school == "NECROMANCY")
    {
        school_of_magic_ = "NECROMANCY";
    }
    else if (new_school == "ILLUSION")
    {
        school_of_magic_ = "ILLUSION";
    }
    else
    {
        school_of_magic_ = "NONE";
    }

    string new_weapon = "";
    for (int i=0; i<weapon.length();i++)
    {
        new_weapon += toupper(weapon[i]);
    }
    
    if (new_weapon == "WAND")
    {
        weapon_ = "WAND";
    }
    else if (new_weapon == "STAFF")
    {
        weapon_ = "STAFF";
    }
    else
    {
        weapon_ = "NONE";
    }

    Character(name, race, vitality, armor, level, enemy);

    can_summon_incarnate_ = incarnate;
}

/**
    @param  : a reference to a string representing the school of magic
    @post   : sets the private member variable to the value of the parameter. If 
              the provided school of magic is not one of the following: [ELEMENTAL, 
              NECROMANCY, ILLUSION], do nothing and return false.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
    @return  : true if setting the variable was successful, false otherwise.
**/

bool Mage::setSchool(const string& school)
{
    string new_school = "";
    for (int i=0; i<school.length();i++)
    {
        new_school += toupper(school[i]);
    }

    if (new_school == "ELEMENTAL")
    {
        school_of_magic_ = "ELEMENTAL";
        return true;
    }
    else if (new_school == "NECROMANCY")
    {
        school_of_magic_ = "NECROMANCY";
        return true;
    }
    else if (new_school == "ILLUSION")
    {
        school_of_magic_ = "ILLUSION";
        return true;
    }
    else
    {
        return false;
    }
}

/**
  @return  : the string indicating the character's school of magic
**/

string Mage::getSchool() const
{
    return school_of_magic_;
}

/**
    @param  : a reference to a string representing the character's weapon
    @post   : sets the private member variable to the value of the parameter.
              String inputs can be in lowercase, but must be converted to 
              uppercase when setting the variable.
              If the provided weapon is not one of the following: 
              [WAND, STAFF], do nothing and return false.
    @return  : true if setting the variable was successful, false otherwise.
**/

bool Mage::setCastingWeapon(const string& weapon)
{
    string new_weapon = "";
    for (int i=0; i<weapon.length();i++)
    {
        new_weapon += toupper(weapon[i]);
    }

    if (new_weapon == "WAND")
    {
        weapon_ = "WAND";
        return true;
    }
    else if (new_weapon == "STAFF")
    {
        weapon_ = "STAFF";
        return true;
    }
    else
    {
        return false;
    }
}

/**
  @return  : the string indicating the character's weapon
**/

string Mage::getCastingWeapon() const
{
    return weapon_;
}

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating whether the character can 
            summon an incarnate
**/

void Mage::setIncarnateSummon(const bool& incarnate)
{
    can_summon_incarnate_ = incarnate;
}

/**
  @return  : the summon-incarnate flag
**/

bool Mage::hasIncarnateSummon() const
{
    return can_summon_incarnate_;
}