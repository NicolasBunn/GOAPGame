#include "EatFruit.h"
#include "Actor.h"

EatFruit::EatFruit()
	: Action(10.0f)
{

}

bool EatFruit::CheckCondition(Actor* a, World& w)
{
	if (w.fruitReady > 0)
	{
		return true;
	}
	return false;
}

void EatFruit::SetEffect(Actor* a, World& w)
{
	a->energy += 1;
	w.fruitReady--;
}

bool EatFruit::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "Finish eating fruit " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Eating fruit ..." << std::endl;

	return false;
}