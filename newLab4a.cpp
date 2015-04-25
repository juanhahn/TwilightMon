#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

class Vampire;
class Werewolf;

class Human
{
	protected:
		int HP, attack, defense, firstStrikeChance;
	public:
		Human(int HP, int attack, int defense, int firstStrikeChance)
		{
			this->HP = HP;
			this->attack = attack;
			this->defense = defense;
			this->firstStrikeChance = firstStrikeChance;
		}
		
		int getHP() {return HP;}
		int getAtk() {return attack;}
		int getDef() {return defense;};
		int getFirstStrikeChance() {return firstStrikeChance;}
		void setHP(int entrada) {HP = entrada;}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3
		
		virtual void receiveAttack(Human *attacker) {};
		virtual void receiveAttack(Vampire *attacker) {this->HP-=attacker->getAtk();}
		virtual void receiveAttack(Werewolf *attacker) {this->HP-=attacker->getAtk();}
};

class Vampire:public Human
{
	private:
		int lifestealAmount;
	public:
		Vampire(int lifestealAmount, int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance)
		{this->lifestealAmount = lifestealAmount;}
		
		int getLSAmount() {return lifestealAmount;}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3
		
		void receiveAttack(Vampire *attacker) {this->hp-=attacker->getAtk();}
		void receiveAttack(Werewolf *attacker) {this->hp-=attacker->getAtk();}
		
};

class Werewolf:public Human
{
	public:
		Werewolf(int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance){}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3
		
		void receiveAttack(Vampire attacker) {this->hp-=attacker->getAtk();}
		void receiveAttack(Werewolf attacker) {this->hp-=attacker->getAtk();}
		
};

class FightManager
{
	private: 
		bool rollTurnOrder;
		int turn;
		string turnWerewolf;
		Human *managerHuman, *fighterA, *fighterB;
		Werewolf *managerWolf;
		Vampire *managerVamp;
	public:
		FightManager(Human *fighterHuman, Werewolf *fighterWolf, Vampire *fighterVamp)
		{
			managerHuman = fighterHuman;
			managerVamp = fighterVamp;
			managerWolf = fighterWolf;
			turn = 0; // valor "Null"
			rollTurnOrder = false; // valor "Null"
		}
		
		Human *firstFighterToAttack()
		{
			int randMax = fighterA->getFirstStrikeChance()+fighterB->getFirstStrikeChance();
		}

		Human *getOpponent(Human *fighter)
		{
			if (fighter == fighterA)
			{
				return fighterB;
			}
			else
			{
				return fighterA;
			}
		}

		void fight()
		{
			Human *attacker;
			Human *target;
			//chose first strike
			while ( both_alive ) {
				attacker = firstFighterToAttack();
				target = getOpponent(attacker);
				attacker->basicAttack(target);
				target->basicAttack(attacker);
			}
		}
		
};

int main()
{
	Human *fighterHuman = new Human(100,12,12,50);
	Vampire *fighterVamp = new Vampire(20,100,10,10,60);
	Werewolf *fighterWolf = new Werewolf(100,16,16,40);
	
	return 0;
}