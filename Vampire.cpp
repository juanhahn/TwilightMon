#include "Human.h"
#include "Vampire.h"
#include "Werewolf.h"
#include <iostream>

using namespace std;

Vampire::Vampire(int lifestealAmount, int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance)
{
	this->lifestealAmount = lifestealAmount;
}
		
int Vampire::getLSAmount() {return lifestealAmount;}
void Vampire::basicAttack(Human *target) {target->receiveAttack(this);}

void Vampire::receiveAttack(Human *attacker) {
	cout << "attacked by Human" << endl;
	this->HP-=attacker->getAtk();
}
void Vampire::receiveAttack(Vampire *attacker) {
	cout << "attacked by Vampire" << endl;
	this->HP-=attacker->getAtk();
}
void Vampire::receiveAttack(Werewolf *attacker) {
	cout << "attacked by Werewolf" << endl;
	this->HP-=attacker->getAtk();
}