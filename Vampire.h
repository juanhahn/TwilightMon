#ifndef __VAMPIRE__
#define __VAMPIRE__

#include "Human.h"
#include "Werewolf.h"

class Vampire:public Human
{
	private:
		int lifestealAmount;
	public:
		Vampire(int lifestealAmount, int HP, int attack, int defense, int firstStrikeChance);
		
		int getLSAmount() {return lifestealAmount;}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3

		virtual void receiveAttack(Human *attacker);
		virtual void receiveAttack(Vampire *attacker);
		virtual void receiveAttack(Werewolf *attacker);
		
};
#endif