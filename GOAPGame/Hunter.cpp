#include "Hunter.h"
#include "Hunt.h"
#include "GetWeapon.h"

Hunter::Hunter(int e)
	: Actor(e)
{
	hunteraActionList.push_back(new GetWeapon());
	hunteraActionList.push_back(new Hunt());
}

void Hunter::DoAction(World& w)
{
	if (currentAction)
	{
		if (currentAction->ExecuteAction(10))
		{
			currentAction->SetEffect(this, w);
			delete currentAction;
			currentAction = nullptr;

			if (currentActionIndice == 0)
			{
				std::cout << "Hunter set current action Hunt ! " << std::endl;
				currentActionIndice = 1;
				currentAction = new Hunt();
			}
			else
			{
				currentActionIndice = -1;
			}
		}
	}
	else
	{
		SelectionAction(w);
	}
}

void Hunter::SelectionAction(World& w)
{
	if (eatAction.CheckCondition(this, w))
	{
		std::cout << "Hunter is hungry ! " << std::endl;
		currentActionIndice = -1;
		if (eatMeatAction.CheckCondition(this, w))
		{
			std::cout << "Hunter is going to eat meat ! " << std::endl;
			currentAction = new EatMeat(eatMeatAction);
			return;
		}
		if (eatFruitAction.CheckCondition(this, w))
		{
			std::cout << "Hunter is going to eat fruit ! " << std::endl;
			currentAction = new EatFruit();
			return;
		}

		std::cout << "Hunter does nothing because their is nothing to eat !" << std::endl;
		return;

	}

	bool huntIsOk = true;
	for (int i = 0; i < hunteraActionList.size(); i++)
	{
		if (!hunteraActionList[i]->CheckCondition(this, w))
		{
			huntIsOk = false;
			break;
		}
	}

	if (huntIsOk)
	{
		std::cout << "Hunter set action getWeapon ! " << std::endl;
		currentAction = new GetWeapon();
		currentActionIndice = 0;
		return;
	}


	if (pickFruitAction.CheckCondition(this, w))
	{
		std::cout << "Hunter set current action pick fruit ! " << std::endl;
		currentAction = new PickFruit(pickFruitAction);
		currentActionIndice = -1;
	}
}

