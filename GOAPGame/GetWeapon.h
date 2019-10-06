#pragma once

#include <iostream>

#include "Action.h"

class Actor;

class GetWeapon :public Action
{
	public:
		GetWeapon();
		bool CheckCondition(Actor* a, World& w) override;
		void SetEffect(Actor* a, World& w) override;
		bool ExecuteAction(float timer) override;
};