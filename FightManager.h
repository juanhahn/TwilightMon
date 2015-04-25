#ifndef __FIGHTMANAGER__
#define __FIGHTMANAGER__

#include "Human.h"
#include "Vampire.h"
#include "Werewolf.h"

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
		FightManager(Human *fighterHuman, Werewolf *fighterWolf, Vampire *fighterVamp);

		void selectFighters(Human *fighter1, Human *fighter2);
		Human *firstFighterToAttack();
		Human *getOpponent(Human *fighter);
		bool bothAlive();
		void fight();
};
#endif