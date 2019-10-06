#include "Eat.h"
#include "Actor.h"

Eat::Eat()
	: Action(10.0f)
{

}

bool Eat::CheckCondition(Actor* a, World& w)
{
	if (a->energy < 3)
	{
		return true;
	}
	return false;
}

void Eat::SetEffect(Actor* a, World& w)
{
	if (w.meatReady > 0)
	{
		a->energy += 3;
		w.meatReady--;
	}
	
	if (w.fruitReady > 0)
	{
		a->energy += 1;
		w.fruitReady--;
	}
	
}

bool Eat::ExecuteAction(float timer)
{
	costAction -= timer;
	if (costAction <= 0.0f)
	{
		std::cout << "Finish eating " << std::endl;
		costAction = 0.0f;
		return true;
	}

	std::cout << "Eating ..." << std::endl;

	return false;
}