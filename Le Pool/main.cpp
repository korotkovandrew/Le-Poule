#include <SFML/Graphics.hpp>
#include "ball.h"

const int SC_W = 320;
const int SC_H = 280;


using namespace sf;
int main()
{
	RenderWindow window(VideoMode(SC_W, SC_H), "SFML Works!");

	// Main Loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.display();
	}

	return 0;
}