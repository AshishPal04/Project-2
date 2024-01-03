#include "Ranger.hpp"

/**
    Default constructor.
    Default-initializes all private members. Default character name: "NAMELESS". 
    Booleans are default-initialized to False. 
*/

Ranger::Ranger()
{
    setName("NAMELESS");
    has_companion_ = false;
    arrows_.clear();
    affinities_.clear();
}

/**
   Parameterized constructor.
  @param      : The name of the character (a const string reference)
  @param      : The race of the character (a const string reference)
  @param      : The character's vitality (an integer). Default to 0
  @param      : The character's max armor level (an integer). Default to 0
  @param      : The character's level (an integer). Default to 0
  @param      : A flag indicating whether the character is an enemy. Default to false
  @param      : A vector of arrows. Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Invalid arrows are those with non-positive quantities or invalid types.
                If the vector contains invalid arrows, those arrows are discarded. 
                Default to empty vector
  @param      : A vector of affinities. Valid Affinities: [FIRE, WATER, POISON, BLOOD]
                String inputs can be in lowercase, but must be converted to uppercase.
                If the vector contains invalid affinities, those affinities are discarded.
                Default to empty vector
  @param      : A flag indicating whether the character is able to recruit an animal companion. 
                Default to false
  @post       : The private members are set to the values of the corresponding parameters
*/

Ranger::Ranger(const string name, const string race, int vitality, int armor, int level, bool enemy, vector<Arrows> arrows, vector<string> affinities, bool has_companion): Character(name, race, vitality, armor, level, enemy)
{
    has_companion_ = has_companion;

    int size1 = affinities.size();
    for (int i=0;i<size1;i++)
    {
        addAffinity(affinities[i]);
    }

    int size2 = arrows.size();
    for (int i=0;i<size2;i++)
    {
        addArrows(arrows[i].type_, arrows[i].quantity_);
    }
}

/**
    @param    : a reference to string representing the arrow type
    @param    : a reference to an integer quantity
    @post     : If the character already has that type of arrow, the quantity in the vector 
                is updated. If not, the arrow is added to the vector. 
                Valid arrow types are: [WOOD, FIRE, WATER, POISON, BLOOD]
                Lowercase valid arrow types are retained but converted to uppercase.
                Quantity of arrows must be greater than 0
                Invalid arrows are those with non-positive quantities or invalid types.
                If the arrows are invalid, they are not added.
    @return   : True if the arrows were added successfully, false otherwise
**/

bool Ranger::addArrows(const string& arrows, const int& number)
{
    if (number < 0)
    {
        return false;
    }

    string new_arrows = "";
    for (int i = 0; i<arrows.length();i++)
    {
        new_arrows += toupper(arrows[i]);
    }

    if ((new_arrows != "WOOD") && (new_arrows != "FIRE") && (new_arrows != "WATER") && (new_arrows != "POISON") && (new_arrows != "BLOOD"))
    {
        return false;
    }

    int size = arrows_.size();

    for (int i=0;i<size;i++)
    {
        if (arrows_[i].type_ == new_arrows)
        {
            arrows_[i].quantity_ += number;
            return true;
        }
    }

    Arrows new_arrow_parm = {new_arrows,number};
    arrows_.push_back(new_arrow_parm);
    return true;
}

/**
  @return     : a vector of the Character's arrows
**/

vector<Arrows> Ranger::getArrows() const
{
    return arrows_;
}

/**
    @param    : a reference to string representing the arrow type
    @post     : If the character has the listed arrow AND enough arrows to fire one, 
                the quantity of remaining arrows in the vector is updated.
                Lowercase valid arrow types are accepted but converted to uppercase.
                If firing the last arrow, simply decrement the quantity to 0.
    @return   : True if the character had the listed arrow AND enough arrows, False otherwise.
**/

bool Ranger::fireArrow(const string& arrows)
{
    string new_arrow = "";
    for (int i=0; i<arrows.length();i++)
    {
        new_arrow += toupper(arrows[i]);
    }

    if ((new_arrow != "WOOD") && (new_arrow != "FIRE") && (new_arrow != "WATER") && (new_arrow != "POISON") && (new_arrow != "BLOOD"))
    {
        return false;
    }

    int size = arrows_.size(); 
    for (int i=0;i<size;i++)
    {
        if ((arrows_[i].type_ == new_arrow) && (arrows_[i].quantity_ > 0))
        {
            arrows_[i].quantity_ -= 1;
            return true;
        }
    }
    
    return false;
}

/**
    @param  : a reference to string representing an affinity 
    @post   : If the affinity does not already exist in the vector, add it to the vector.
              Valid Affinities: [FIRE, WATER, POISON, BLOOD] 
              String inputs can be in lowercase, but must be converted to uppercase when 
              setting the variable.
              There should be no duplicate affinities.
              If the affinity is invalid, it is NOT added.
    @return : True if the affinity was added successfully, false otherwise
**/

bool Ranger::addAffinity(const string& affinity)
{
    string new_affinity = "";
    for (int i=0;i<affinity.length();i++)
    {
        new_affinity += toupper(affinity[i]);
    }

    if ((new_affinity != "FIRE") && (new_affinity != "WATER") && (new_affinity != "POISON") && (new_affinity != "BLOOD"))
    {
        return false;
    }

    int size = affinities_.size();

    for (int i=0;i<size;i++)
    {
        if (affinities_[i] == new_affinity)
        {
            return false;
        }
    }

    affinities_.push_back(new_affinity);
    return true;
}

/**
  @return     : a vector of the Character's affinities
**/

vector<string> Ranger::getAffinities() const
{
    return affinities_;
}

/**
    @param    : a reference to a boolean indicating whether the character is able to recruit 
                an animal companion
    @post     : sets the private member variable to the value of the parameter.
**/

void Ranger::setCompanion(const bool& companion)
{
    has_companion_ = companion;
}

/**
    @return   : a boolean indicating whether the character is able to recruit an animal companion
**/

bool Ranger::getCompanion() const
{
    return has_companion_;
}
