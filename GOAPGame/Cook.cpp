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
		std::cout << "Cook is hungry ! " << std::endl;
		currentActionIndice = -1;
		if (eatMeatAction.CheckCondition(this, w))
		{
			std::cout << "Cook is going to eat meat ! " << std::endl;
			currentAction = new EatMeat(eatMeatAction);
			return;
		}
		if (eatFruitAction.CheckCondition(this, w))
		{
			std::cout << "Cook is going to eat fruit ! " << std::endl;
			currentAction = new EatFruit();
			return;
		}

		std::cout << "Cook does nothing because their is nothing to eat !" << std::endl;
		return;
	}

	if (cookMeatAction.CheckCondition(this, w))
	{
		std::cout << "Cook set  current cook meat ! " << std::endl;
		currentAction = new CookMeat(cookMeatAction);
		return;
	}

	if (cookFruitAction.CheckCondition(this, w))
	{
		std::cout << "Cook set  current cook fruit ! " << std::endl;
		currentAction = new CookFruit(cookFruitAction);
		return;
	}

	std::cout << "Cook do Nothing ! " << std::endl;
}

