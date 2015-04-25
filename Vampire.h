#ifndef __Vampire__
#define __Vampire__

class Vampire:public Human
{
	private:
		int lifestealAmount;
	public:
		Vampire(int lifestealAmount, int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance);
		
		int getLSAmount() {return lifestealAmount;}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3

		virtual void receiveAttack(Human *attacker);
		virtual void receiveAttack(Vampire *attacker);
		virtual void receiveAttack(Werewolf *attacker);
		
};
#endif