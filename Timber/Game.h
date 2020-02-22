#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML\Window\VideoMode.hpp>

class Game
{

private:
	static const int NUM_BRANCHES = 6;
	bool isGamePused;
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

	sf::Sprite spriteBranchs[NUM_BRANCHES];
	sf::Texture textureBranch;

	sf::RectangleShape timeBar;


private:
	void setWindow();
	void setBackground();

public:
	Game();
	~Game();
	void intializeGame();
	void startGame();
	void ScanKeyboard();
	void createClouds();
	void createTrees();
	void createBee();
	void createTimebar();
	void moveClouds();
	void moveBeeLeft();
	void moveBeeRight();
	void createScoreText();
	void createBranches();
	void updateBranches();
	int GetRandomNumber(int start,int end);
	
};
