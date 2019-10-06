#pragma once

#include <iostream>

#include "Action.h"

class Actor;

class Hunt :public Action
{
	public:
		Hunt();
		bool CheckCondition(Actor* a, World& w) override;
		void SetEffect(Actor* a, World& w) override;
		bool ExecuteAction(float timer) override;
};