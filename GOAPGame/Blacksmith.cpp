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
		std::cout << "Blacksmith is hungry ! " << std::endl;
		currentActionIndice = -1;
		if (eatMeatAction.CheckCondition(this, w))
		{
			std::cout << "Blacksmith is going to eat meat ! " << std::endl;
			currentAction = new EatMeat(eatMeatAction);
			return;
		}
		if (eatFruitAction.CheckCondition(this, w))
		{
			std::cout << "Blacksmith is going to eat fruit ! " << std::endl;
			currentAction = new EatFruit();
			return;
		}

		std::cout << "Blacksmith does nothing because their is nothing to eat !" << std::endl;
		return;
	}

	if (forgeAction.CheckCondition(this,w))
	{
		std::cout << "Blacksmith set current action forge ! " << std::endl;
		currentAction = new Forge(forgeAction);
	}
}

