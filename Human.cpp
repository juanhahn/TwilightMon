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

int Human::getHP() {return HP;}
int Human::getAtk() {return attack;}
int Human::getDef() {return defense;}
int Human::getFirstStrikeChance() {return firstStrikeChance;}
void Human::setHP(int entrada) {HP = entrada;}

void Human::basicAttack(Human *target) {target->receiveAttack(this);}

void Human::receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();}
void Human::receiveAttack(Vampire *attacker) {this->HP-=attacker->getAtk();}
void Human::receiveAttack(Werewolf *attacker) {this->HP-=attacker->getAtk();}
