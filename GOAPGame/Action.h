#pragma once

#include "World.h"

class Actor;

class Action
{
	public:
		Action(float c = 0.0f);
		Action(const Action& a);

		virtual bool CheckCondition(Actor* a, World& w) = 0;
		virtual void SetEffect(Actor* a, World& w) = 0;

		virtual bool ExecuteAction(float timer) = 0;

		float costAction;

};