#include "Human.h"
#include "Vampire.h"
#include "Werewolf.h"

Werewolf::Werewolf(int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance) {}

void Werewolf::basicAttack(Human *target) {target->receiveAttack(this);}
// attack n°2
// attack n°3

void Werewolf::receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();}
void Werewolf::receiveAttack(Vampire *attacker) {this->HP-=attacker->getAtk();}
void Werewolf::receiveAttack(Werewolf *attacker) {this->HP-=attacker->getAtk();}