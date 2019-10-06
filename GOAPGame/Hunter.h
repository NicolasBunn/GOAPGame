#pragma once

#include <vector>

#include "Actor.h"
#include "PickFruit.h"
#include "Eat.h"
#include "EatFruit.h"
#include "EatMeat.h"

class Hunter : public Actor
{
public:
	Hunter(int e = 0);

	void DoAction(World& w) override;
	void SelectionAction(World& w) override;

	Eat  eatAction;
	EatFruit eatFruitAction;
	EatMeat eatMeatAction;
	PickFruit pickFruitAction;

	std::vector<Action*> hunteraActionList;

};
