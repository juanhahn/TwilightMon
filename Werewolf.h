#ifndef __WEREWOLF__
#define __WEREWOLF__

#include "Vampire.h"
#include "Human.h"

class Human;

class Werewolf:public Human
{
	public:
		Werewolf(int HP, int attack, int defense, int firstStrikeChance);
		
		void basicAttack(Human *target);
		// attack n°2
		// attack n°3

		void receiveAttack(Human *attacker);
		void receiveAttack(Vampire *attacker);
		void receiveAttack(Werewolf *attacker);
		
};
#endif