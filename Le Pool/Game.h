#pragma once

#include <SFML/Graphics.hpp>

// Constant variables

//

/*
	Wrapper class for all game things.
*/
class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;

	// Private functions
	void initVariables();
	void initWindow();

public:
	// Constructors & Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Functions
	void pollEvents();
	void update();
	void render();
};

