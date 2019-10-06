#include <iostream>

#include "Hunter.h"
#include "Cook.h"
#include "Blacksmith.h"
#include "World.h"

void DisplayWorldData(World& w)
{
	std::cout << "weapon " << w.weapon << std::endl;
	std::cout << "Meat " << w.meat << std::endl;
	std::cout << "Meat ready " << w.meatReady << std::endl;
	std::cout << "Fruit " << w.fruit << std::endl;
	std::cout << "Fruit ready " << w.fruitReady << std::endl;
}

int main(int argc, char* argv[])
{
	World w;
	Blacksmith b(10);
	Cook c(15);
	Hunter h(10);

	int turn = 0;

	bool pause = false;
	
	while (turn < 20)
	{
		DisplayWorldData(w);

		std::cout << "Hunter health " << h.energy << std::endl;
		std::cout << "Blacksmith health " << b.energy << std::endl;
		std::cout << "Cook health " << c.energy << std::endl;

		h.DoAction(w);
		b.DoAction(w);
		c.DoAction(w);

		turn++;

		if (pause)
		{
			getchar();
		}
	}

	return 0;
}