#include "Human.h"
#include "Vampire.h"
#include "Werewolf.h"
#include <iostream>

using namespace std;

Werewolf::Werewolf(int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance) {}

void Werewolf::basicAttack(Human *target) {target->receiveAttack(this);}
// attack n°2
// attack n°3

void Werewolf::receiveAttack(Human *attacker) {
	cout << "attacked by Human" << endl;
	this->HP-=attacker->getAtk();
}
void Werewolf::receiveAttack(Vampire *attacker) {
	cout << "attacked by Vampire" << endl;
	this->HP-=attacker->getAtk();
}
void Werewolf::receiveAttack(Werewolf *attacker) {
	cout << "attacked by Werewolf" << endl;
	this->HP-=attacker->getAtk();
}