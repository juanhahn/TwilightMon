#ifndef __WEREWOLF__
#define __WEREWOLF__

#include "Vampire.h"
#include "Human.h"

class Werewolf:public Human
{
	public:
		Werewolf(int HP, int attack, int defense, int firstStrikeChance);
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3

		virtual void receiveAttack(Human *attacker);
		virtual void receiveAttack(Vampire attacker);
		virtual void receiveAttack(Werewolf attacker);
		
};
#endif