#pragma once

#include "Action.h"

class CookFruit : public Action
{
public:
	CookFruit();

	bool CheckCondition(Actor* a, World& w) override;
	void SetEffect(Actor* a, World& w) override;
	bool ExecuteAction(float timer) override;
};