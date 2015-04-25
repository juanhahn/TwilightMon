#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

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
		
		virtual void receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();};
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

		virtual void receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();};
		virtual void receiveAttack(Vampire *attacker) {this->HP-=attacker->getAtk();}
		virtual void receiveAttack(Werewolf *attacker) {this->HP-=attacker->getAtk();}
		
};

class Werewolf:public Human
{
	public:
		Werewolf(int HP, int attack, int defense, int firstStrikeChance):Human(HP, attack, defense, firstStrikeChance){}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3

		virtual void receiveAttack(Human *attacker) {this->HP-=attacker->getAtk();};
		virtual void receiveAttack(Vampire attacker) {this->HP-=attacker->getAtk();}
		virtual void receiveAttack(Werewolf attacker) {this->HP-=attacker->getAtk();}
		
};

class FightManager
{
	private: 
		bool rollTurnOrder;
		int turn;
		string turnWerewolf;
		Human *fighterHuman, *fighterA, *fighterB;
		Werewolf *fighterWolf;
		Vampire *fighterVamp;
	public:
		FightManager(Human *fighterHuman, Werewolf *fighterWolf, Vampire *fighterVamp)
		{
			fighterHuman = fighterHuman;
			fighterVamp = fighterVamp;
			fighterWolf = fighterWolf;
			turn = 0; // valor "Null"
			rollTurnOrder = false; // valor "Null"
		}

		void selectFighters(Human *fighter1, Human *fighter2)
		{
			fighterA = fighter1;
			fighterB = fighter2;
		}
		
		Human *firstFighterToAttack()
		{
			return fighterA; // simplified version for now
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

		bool bothAlive() {
			return fighterA->getHP() > 0 && fighterB->getHP() > 0;
		}

		void fight()
		{
			Human *attacker;
			Human *target;
			//chose first strike
			while ( bothAlive() ) {
				attacker = firstFighterToAttack();
				target = getOpponent(attacker);
				attacker->basicAttack(target);
				target->basicAttack(attacker);
				cout << "target's HP: " << target->getHP() << endl;
			}
		}
		
};

int main()
{
	Human *fighterHuman = new Human(100,12,12,50);
	Vampire *fighterVamp = new Vampire(20,100,10,10,60);
	Werewolf *fighterWolf = new Werewolf(100,16,16,40);

	FightManager *fm = new FightManager(fighterHuman, fighterWolf, fighterVamp);
	fm->selectFighters(fighterHuman, fighterVamp);
	fm->fight();
	
	return 0;
}