#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML\Window\VideoMode.hpp>

class Game
{

private:
	sf::VideoMode vm;
	sf::RenderWindow window;
	sf::Sprite spriteBackground;
	sf::Texture textureBackground;

private:
	void setWindow();
	void setBackground();

public:
	Game();
	
	void startGame();
	void stopGame();
	void puaseGame();
	void createClouds();
	void createBee();
};
