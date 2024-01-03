#include "Mage.hpp"
#include "Character.hpp"
#include "Scoundrel.hpp"
#include "Ranger.hpp"
#include "Barbarian.hpp"


int main(){
Mage defaultMage;
defaultMage.setName("defaultMage");
defaultMage.setRace("ELF");
defaultMage.setVitality(5);
defaultMage.setArmor(3);
defaultMage.setLevel(2);
defaultMage.setEnemy();


cout<<"defaultMage is a Level "<<defaultMage.getLevel()<<" "<<defaultMage.getRace()<<"."<<endl; 
cout<<"Vitality: "<<defaultMage.getVitality()<<endl; 
cout<<"Armor: "<<defaultMage.getArmor()<<endl; 
cout<<"They are "<<(defaultMage.isEnemy() ? "an enemy" : " not an enemy")<<endl;


Mage paramMage("SPYNACH", "ELF", 6, 4, 4, false);
paramMage.setSchool("Illusion");
paramMage.setCastingWeapon("Wand");
paramMage.setIncarnateSummon(true);
cout<<endl;
cout<<paramMage.getName()<<" is a Level "<<paramMage.getLevel()<<" "<<paramMage.getRace()<<"."<<endl;
cout<<"Vitality: "<<paramMage.getVitality()<<endl;
cout<<"Armor: "<<paramMage.getArmor()<<endl;
cout<<"They are "<<(paramMage.isEnemy() ? "an enemy" : "not an enemy")<<endl;
cout<<"School of Magic: "<<paramMage.getSchool()<<endl;
cout<<"Weapon: "<<paramMage.getCastingWeapon()<<endl;
cout << "Summon Incarnate: " << (paramMage.hasIncarnateSummon() ? "TRUE" : "FALSE")<<"\n";

Scoundrel defaultScoundrel;
defaultScoundrel.setName("defaultScoundrel");
defaultScoundrel.setRace("HUMAN");
defaultScoundrel.setVitality(6);
defaultScoundrel.setArmor(4);
defaultScoundrel.setLevel(3);
defaultScoundrel.setEnemy();


cout<<endl;
cout<<"defaultScoundrel is a Level "<<defaultScoundrel.getLevel()<<" "<<defaultScoundrel.getRace()<<"."<<endl;
cout<<"Vitality: "<<defaultScoundrel.getVitality()<<endl;
cout<<"Armor: "<<defaultScoundrel.getArmor()<<endl;
cout<<"They are "<<(defaultScoundrel.isEnemy() ? "an enemy" : " not an enemy")<<endl<<"";

Scoundrel paramScoundrel("FLEA", "DWARF", 12, 7, 5, false);
paramScoundrel.setDagger("Adamant");
paramScoundrel.setFaction("Cutpurse");
paramScoundrel.setDisguise(true);

cout<<endl;
cout<<paramScoundrel.getName()<<" is a Level "<<paramScoundrel.getLevel()<<" "<<paramScoundrel.getRace()<<"."<<endl;
cout<<"Vitality: "<<paramScoundrel.getVitality()<<endl;
cout<<"Armor: "<<paramScoundrel.getArmor()<<endl;
cout<<"They are"<<(paramScoundrel.isEnemy() ? "an enemy" : " not an enemy")<<endl;
cout<<"Dagger: "<<paramScoundrel.getDagger()<<endl;
cout<<"Faction: "<<paramScoundrel.getFaction()<<endl;
cout << "Disguise: " << (paramScoundrel.hasDisguise() ? "TRUE" : "FALSE") <<endl;


Ranger defaultRanger; 

defaultRanger.setName("defaultRanger");
defaultRanger.setRace("UNDEAD");
defaultRanger.setVitality(8);
defaultRanger.setArmor(4);
defaultRanger.setLevel(5);
defaultRanger.setEnemy();

cout << endl;
cout << "defaultRanger is a Level " << defaultRanger.getLevel() << " " << defaultRanger.getRace() << "." <<endl;
cout << "Vitality: " << defaultRanger.getVitality() << endl;
cout << "Armor: " << defaultRanger.getArmor() << endl;
cout << "They are " << (defaultRanger.isEnemy() ? "an enemy" : " not an enemy") <<endl;
cout << "Arrows: \n";
cout << "Affinities: ";
cout << endl;
cout << boolalpha;
cout << "Animal Companion: " << (defaultRanger.getCompanion() ? "TRUE" : "FALSE") <<endl;


Ranger paramRanger("MARROW", "UNDEAD", 9, 6, 5, true);
paramRanger.addArrows("Wood", 30);
paramRanger.addArrows("Fire", 5);
paramRanger.addArrows("Water", 5);
paramRanger.addArrows("Poison", 5);
paramRanger.addAffinity("Fire");
paramRanger.addAffinity("Poison");
paramRanger.setCompanion(true);


cout<<endl;
cout<<paramRanger.getName()<<" is a Level "<<paramRanger.getLevel()<<" "<<paramRanger.getRace()<<"."<<endl;
cout<<"Vitality: "<<paramRanger.getVitality()<<endl;
cout<<"Armor: "<<paramRanger.getArmor()<<endl;
cout<<"They are "<<(paramRanger.isEnemy() ? "an enemy" : " not an enemy")<<endl;
cout<<"Vector of arrows: ";
const vector<Arrows> arrows = paramRanger.getArrows();
for (int i=0;i<arrows.size();i++){
cout << arrows[i].type_ <<", "<<arrows[i].quantity_;
    if (i<arrows.size() -1){
        cout <<", ";
    }
}
cout<<endl;
cout<<"Affinities: ";
vector<string> affinities = paramRanger.getAffinities();
for (int j=0;j<affinities.size();j++){
    cout<<affinities[j];
    if(j<affinities.size() -1){
        cout<<", ";
    }
}
cout<<endl;
cout << boolalpha;
cout << "Animal Companion: " << (paramRanger.getCompanion() ? "TRUE" : "FALSE") << endl;

Barbarian defaultBarbarian;
defaultBarbarian.setName("defaultBarbarian");
defaultBarbarian.setRace("HUMAN");
defaultBarbarian.setVitality(10);
defaultBarbarian.setArmor(5);
defaultBarbarian.setLevel(5);
defaultBarbarian.setEnemy();
defaultBarbarian.setMainWeapon("NONE");
defaultBarbarian.setSecondaryWeapon("NONE");
defaultBarbarian.setEnrage(false);

cout<<endl;
cout<<"defaultBarbarian is a Level "<<defaultBarbarian.getLevel()<<" "<<defaultBarbarian.getRace()<<"."<<endl;
cout<<"Vitality: "<<defaultBarbarian.getVitality()<<endl;
cout<<"Armor: "<<defaultBarbarian.getArmor()<<endl;
cout<<"They are "<<(defaultBarbarian.isEnemy() ? "an enemy" : " not an enemy")<<endl;
cout<<"Main Weapon: "<<defaultBarbarian.getMainWeapon()<<endl;
cout<<"Offhand Weapon: "<<defaultBarbarian.getSecondaryWeapon()<<endl;
cout<<"Enraged: "<<(defaultBarbarian.getEnrage()? "TRUE" : "FALSE") << endl;


Barbarian paramBarbarian("BONK","HUMAN",11,6,5,false);
paramBarbarian.setMainWeapon("MACE");
paramBarbarian.setSecondaryWeapon("ANOTHERMACE");
paramBarbarian.setEnrage(true);

cout<<endl;
cout<<paramBarbarian.getName()<<" is a Level "<<paramBarbarian.getLevel()<<" "<<paramBarbarian.getRace()<<"."<<endl;
cout<<"Vitality: "<<paramBarbarian.getVitality()<<endl;
cout<<"Armor: "<<paramBarbarian.getArmor()<<endl;
cout<<"They are "<<(paramBarbarian.isEnemy() ? "an enemy" : "not an enemy")<<endl;
cout<<"Main Weapon: "<<paramBarbarian.getMainWeapon()<<endl;
cout<<"Offhand Weapon: "<<paramBarbarian.getSecondaryWeapon()<<endl;
cout<<"Enraged: "<<(paramBarbarian.getEnrage()? "TRUE" : "FALSE") << endl;

}