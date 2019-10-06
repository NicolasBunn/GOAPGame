#pragma once

#include "Action.h"

class CookMeat : public Action
{
public:
	CookMeat();

	bool CheckCondition(Actor* a, World& w) override;
	void SetEffect(Actor* a, World& w) override;
	bool ExecuteAction(float timer) override;
};