#include "Blacksmith.h"

Blacksmith::Blacksmith(int e)
	: Actor(e)
{

}

void Blacksmith::DoAction(World& w)
{
	if (currentAction)
	{
		if (currentAction->ExecuteAction(10))
		{
			currentAction->SetEffect(this, w);
			delete currentAction;
			currentAction = nullptr;
		}


	}
	else
	{
		SelectionAction(w);
	}
}

void Blacksmith::SelectionAction(World& w)
{
	if (eatAction.CheckCondition(this, w))
	{
		currentAction = new Eat(eatAction);
		std::cout << "Set current action eat ! " << std::endl;
		return;
	}

	if (forgeAction.CheckCondition(this,w))
	{
		std::cout << "Set current action forge ! " << std::endl;
		currentAction = new Forge(forgeAction);
	}
}

