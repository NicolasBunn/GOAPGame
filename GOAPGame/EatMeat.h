#pragma once

#include "Action.h"

class EatMeat : public Action
{
public:
	EatMeat();

	bool CheckCondition(Actor* a, World& w) override;
	void SetEffect(Actor* a, World& w) override;
	bool ExecuteAction(float timer) override;
};