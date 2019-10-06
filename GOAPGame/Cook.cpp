#include "Cook.h"

Cook::Cook(int e)
	: Actor(e)
{

}

void Cook::DoAction(World& w)
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

void Cook::SelectionAction(World& w)
{
	if (eatAction.CheckCondition(this, w))
	{
		std::cout << "Set current action eat ! " << std::endl;
		currentAction = new Eat(eatAction);
		return;
	}

	if (cookMeatAction.CheckCondition(this, w))
	{
		std::cout << "Set current cook meat ! " << std::endl;
		currentAction = new CookMeat(cookMeatAction);
		return;
	}

	if (cookFruitAction.CheckCondition(this, w))
	{
		std::cout << "Set current cook fruit ! " << std::endl;
		currentAction = new CookFruit(cookFruitAction);
		return;
	}

	std::cout << "Cook do Nothing ! " << std::endl;
}

