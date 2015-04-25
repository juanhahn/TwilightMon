#include "Human.h"
#include "Vampire.h"
#include "Werewolf.h"

Human::Human(int HP, int attack, int defense, int firstStrikeChance)
{
	this->HP = HP;
	this->attack = attack;
	this->defense = defense;
	this->firstStrikeChance = firstStrikeChance;
}

virtual void Human::receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();};
virtual void Human::receiveAttack(Vampire *attacker) {this->HP-=attacker->getAtk();}
virtual void Human::receiveAttack(Werewolf *attacker) {this->HP-=attacker->getAtk();}
