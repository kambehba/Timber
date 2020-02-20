#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML\Window\VideoMode.hpp>

class Game
{

private:
	bool isBeeMovingLeft;
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

	sf::Sprite spriteBee;
	sf::Texture textureBee;

	sf::Text scoreText;
	sf::Font font;


private:
	void setWindow();
	void setBackground();

public:
	Game();
	~Game();
	void intializeGame();
	void startGame();
	void createClouds();
	void createTrees();
	void createBee();
	void moveClouds();
	void moveBeeLeft();
	void moveBeeRight();
	void createScoreText();
	int GetRandomNumber(int start,int end);
	
};
