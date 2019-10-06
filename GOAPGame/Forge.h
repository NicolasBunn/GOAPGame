#pragma once

#include <iostream>

#include "Action.h"

class Actor;

class Forge :public Action
{
	public:
		Forge();
		bool CheckCondition(Actor* a, World& w) override;
		void SetEffect(Actor* a, World& w) override;
		bool ExecuteAction(float timer) override;
};