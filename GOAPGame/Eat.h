#pragma once

#include "Action.h"

class Eat : public Action
{
	public:
		Eat();

		bool CheckCondition(Actor* a, World& w) override;
		void SetEffect(Actor* a, World& w) override;
		bool ExecuteAction(float timer) override;
};