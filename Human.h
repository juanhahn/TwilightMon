#ifndef __HUMAN__
#define __HUMAN__
class Human
{
	protected:
		int HP, attack, defense, firstStrikeChance;
	public:
		Human(int HP, int attack, int defense, int firstStrikeChance);
		
		int getHP() {return HP;}
		int getAtk() {return attack;}
		int getDef() {return defense;};
		int getFirstStrikeChance() {return firstStrikeChance;}
		void setHP(int entrada) {HP = entrada;}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3
		
		virtual void receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();};
		virtual void receiveAttack(Vampire *attacker) {this->HP-=attacker->getAtk();}
		virtual void receiveAttack(Werewolf *attacker) {this->HP-=attacker->getAtk();}
};
#endif