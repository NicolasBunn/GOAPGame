#include "CookFruit.h"
#include "Actor.h"

CookFruit::CookFruit()
	: Action(30.0f)
{

}

bool CookFruit::CheckCondition(Actor* a, World& w)
{
	if (w.fruit > 0)
	{
		return true;
	}

	return false;
}


void CookFruit::SetEffect(Actor* a, World& w)
{
	w.fruit -= 1;
	w.fruitReady += 1;
}

bool CookFruit::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "Cooking fruit finish  " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Cooking fruit ..." << std::endl;

	return false;
}