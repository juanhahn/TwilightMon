#include "Human.h"
#include "Vampire.h"
#include "Werewolf.h"

Vampire::Vampire(int lifestealAmount, int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance)
{
	this->lifestealAmount = lifestealAmount;
}
		
int Vampire::getLSAmount(); {return lifestealAmount;}
void Vampire::basicAttack(Human *target) {target->receiveAttack(this);}

virtual void Vampire::receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();}
virtual void Vampire::receiveAttack(Vampire *attacker) {this->HP-=attacker->getAtk();}
virtual void Vampire::receiveAttack(Werewolf *attacker) {this->HP-=attacker->getAtk();}