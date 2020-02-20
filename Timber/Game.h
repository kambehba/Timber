#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML\Window\VideoMode.hpp>

class Game
{

private:
	sf::Clock clock;
	sf::Time dt;
	sf::VideoMode vm;
	sf::RenderWindow window;
	sf::Sprite spriteBackground;
	sf::Texture textureBackground;

	sf::Sprite spriteCloud1;
	sf::Sprite spriteCloud2;
	sf::Sprite spriteCloud3;
	sf::Texture textureCloud;

	sf::Sprite spriteTree;
	sf::Texture textureTree;

private:
	void setWindow();
	void setBackground();

public:
	Game();
	~Game();
	void startGame();
	void createClouds();
	void createTrees();
	void moveClouds();
	int GetRandomNumber(int start,int end);
	
};
