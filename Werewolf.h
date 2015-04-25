#ifndef __Werewolf__
#define __Werewolf__

class Werewolf:public Human
{
	public:
		Werewolf(int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance);
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3

		virtual void receiveAttack(Human *attacker);
		virtual void receiveAttack(Vampire attacker);
		virtual void receiveAttack(Werewolf attacker);
		
};
#endif