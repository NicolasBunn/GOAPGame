
#pragma once

#include "Actor.h"
#include "CookMeat.h"
#include "CookFruit.h"
#include "Eat.h"

class Cook : public Actor
{
public:
	Cook(int e = 0);

	void DoAction(World& w) override;
	void SelectionAction(World& w) override;

	Eat  eatAction;
	CookMeat cookMeatAction;
	CookFruit cookFruitAction;
};
