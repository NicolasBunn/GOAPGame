#pragma once

#include "Action.h"

class EatFruit : public Action
{
public:
	EatFruit();

	bool CheckCondition(Actor* a, World& w) override;
	void SetEffect(Actor* a, World& w) override;
	bool ExecuteAction(float timer) override;
};