#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

/*=====================================================================================
Crea el objeto "Human"
=====================================================================================*/			
class Human
{
	protected:
		int HP, attack, defense, firstStrikeChance;
		string type;
	public:
		Human(int HP, int attack, int defense, int firstStrikeChance, string type)
		{
			this->HP = HP;
			this->atk = atk;
			this->def = def;
			this->firstStrikeChance = firstStrikeChance;
			this->type = type;
		}
		
		int getHP() {return HP;}
		int getAtk() {return attack;}
		int getDef() {return defense;};
		int getFirstStrikeChance() {return firstStrikeChance;}
		string getType() {return type;}
		void setHP(int entrada) {HP = entrada;}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3
		
		void receiveAttack(Vampire attacker) {this.hp-=attacker.attack;}
		void receiveAttack(Werewolf attacker) {this.hp-=attacker.attack;}
};
/*=====================================================================================
Crea el objeto "Vampire"
=====================================================================================*/
class Vampire:public Human
{
	private:
		int lifestealAmount;
	public:
		Vampire(int lifestealAmount, int HP, int attack, int defense, int firstStrikeChance, string type):Human(HP, attack, defense, firstStrikeChance, type)
		{this->lifestealAmount = lifestealAmount;}
		
		int getLSAmount() {return lifestealAmount;}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3
		
		void receiveAttack(Vampire attacker) {this.hp-=attacker.attack;}
		void receiveAttack(Werewolf attacker) {this.hp-=attacker.attack;}
		
};
/*=====================================================================================
Crea el objeto "Werewolf"
=====================================================================================*/
class Werewolf:public Human
{
	public:
		Werewolf(int HP, int attack, int defense, int firstStrikeChance, string type):Human(HP, attack, defense, firstStrikeChance, type){}
		
		void basicAttack(Human *target) {target->receiveAttack(this);}
		// attack n°2
		// attack n°3
		
		void receiveAttack(Vampire attacker) {this.hp-=attacker.attack;}
		void receiveAttack(Werewolf attacker) {this.hp-=attacker.attack;}
		
};
/*=====================================================================================
Crea el objeto "FightManager"
=====================================================================================*/
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
		
		
		
		bool rollOrder()
		{
			int randMax = fighterA->getType()+fighterB->getType();
		}
		
};

int main()
{
	Human *fighterHuman = new Human(100,12,12,50,"Human");
	Vampire *fighterVamp = new Vampire(20,100,10,10,60,"Vampire");
	Werewolf *fighterWolf = new Werewolf(100,16,16,40,"Werewolf")
	
	return 0;
}