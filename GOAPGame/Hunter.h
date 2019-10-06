#pragma once

#include <vector>

#include "Actor.h"
#include "Hunt.h"
#include "PickFruit.h"
#include "Eat.h"

class Hunter : public Actor
{
public:
	Hunter(int e = 0);

	void DoAction(World& w) override;
	void SelectionAction(World& w) override;

	Eat  eatAction;
	Hunt huntAction;
	PickFruit pickFruitAction;

	std::vector<Action*> hunteraActionList;

};
