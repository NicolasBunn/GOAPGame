#pragma once

#include "Actor.h"
#include "Forge.h"
#include "Eat.h"

class Blacksmith : public Actor
{
	public:
		Blacksmith(int e = 0);

		void DoAction(World& w) override;
		void SelectionAction(World& w) override;

		Eat eatAction;
		Forge forgeAction;
};