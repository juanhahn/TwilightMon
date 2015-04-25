#include "FightManager.h"
#include <iostream>

using namespace std;

FightManager::FightManager(Human *fighterHuman, Werewolf *fighterWolf, Vampire *fighterVamp)
{
	fighterHuman = fighterHuman;
	fighterVamp = fighterVamp;
	fighterWolf = fighterWolf;
	turn = 0; // valor "Null"
	rollTurnOrder = false; // valor "Null"
}

void FightManager::selectFighters(Human *fighter1, Human *fighter2)
{
	fighterA = fighter1;
	fighterB = fighter2;
}

Human *FightManager::firstFighterToAttack()
{
	return fighterA; // simplified version for now
}

Human *FightManager::getOpponent(Human *fighter)
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

bool FightManager::bothAlive() {
	return fighterA->getHP() > 0 && fighterB->getHP() > 0;
}

void FightManager::fight()
{
	Human *attacker;
	Human *target;
	//chose first strike
	while ( bothAlive() ) {
		attacker = firstFighterToAttack();
		target = getOpponent(attacker);
		attacker->basicAttack(target);
		cout << "target's HP: " << target->getHP() << endl;
		target->basicAttack(attacker);
		cout << "target's HP: " << attacker->getHP() << endl;
	}
}

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