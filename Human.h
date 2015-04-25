#ifndef __HUMAN__
#define __HUMAN__

class Vampire;
class Werewolf;

class Human
{
	protected:
		int HP, attack, defense, firstStrikeChance;
	public:
		Human(int HP, int attack, int defense, int firstStrikeChance);
		
		int getHP();
		int getAtk();
		int getDef();
		int getFirstStrikeChance();
		void setHP(int entrada);
		
		void basicAttack(Human *target);
		// attack n°2
		// attack n°3
		
		void receiveAttack(Human *attacker);
		void receiveAttack(Vampire *attacker);
		void receiveAttack(Werewolf *attacker);
};
#endif