#pragma once

#include <iostream>

#include "Action.h"
#include "World.h"

class Actor
{
	public:
		Actor(int e);

		int energy;
		int currentActionIndice = 0;

		Action* currentAction;

		virtual void DoAction(World& w);
		virtual void SelectionAction(World& w);
};