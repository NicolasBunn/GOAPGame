#include "CookMeat.h"
#include "Actor.h"

CookMeat::CookMeat()
	: Action(20.0f)
{

}

bool CookMeat::CheckCondition(Actor* a, World& w)
{
	if (w.meat > 0)
	{
		return true;
	}

	return false;
}


void CookMeat::SetEffect(Actor* a, World& w)
{
	w.meat -= 1;
	w.meatReady += 3;
}

bool CookMeat::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "Cooking meat finish  " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Cooking meat ..." << std::endl;

	return false;
}