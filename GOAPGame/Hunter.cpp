#include "Hunter.h"
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
				std::cout << "Set current action Hunt ! " << std::endl;
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
		std::cout << "Set current action eat ! " << std::endl;
		currentAction = new Eat(eatAction);
		currentActionIndice = -1;
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
		std::cout << "Set current action getWeapon ! " << std::endl;
		currentAction = new GetWeapon();
		currentActionIndice = 0;
		return;
	}


	if (pickFruitAction.CheckCondition(this, w))
	{
		std::cout << "Set current action pick fruit ! " << std::endl;
		currentAction = new PickFruit(pickFruitAction);
		currentActionIndice = -1;
	}
}

