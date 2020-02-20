#include "Game.h"
using namespace sf;

Game::Game() 
{
	intializeGame();
	
}

void Game::intializeGame()
{
	isBeeMovingLeft = true;
	setWindow();
	setBackground();
	createClouds();
	createTrees();
	createBee();
	createScoreText();
}

void Game::startGame()
{
	try
	{
		intializeGame();
		while (true)
		{
			dt = clock.restart();
			
			window.clear();
			
			window.draw(spriteBackground);
			window.draw(spriteCloud1);
			window.draw(spriteCloud2);
			window.draw(spriteCloud3);
			window.draw(spriteTree);
			window.draw(spriteBee);
			window.draw(scoreText);
			
			window.display();

			moveClouds();

			if (isBeeMovingLeft) moveBeeLeft();
			else moveBeeRight();
			

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
				return;
			}
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}
}

void Game::setWindow()
{
	window.create(vm.getDesktopMode(), "Timber!!!", Style::Fullscreen);
}

void Game::setBackground()
{
	textureBackground.loadFromFile("graphics\\background.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
}

void Game::createTrees()
{
	textureTree.loadFromFile("graphics\\tree.png");
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);
}

void Game::createBee()
{
	textureBee.loadFromFile("graphics\\bee_right.png");
	spriteBee.setTexture(textureBee);
	spriteBee.scale(0.5f,0.5f);
	
	
}

void Game::createClouds()
{
	textureCloud.loadFromFile("graphics\\cloud.png");

	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
}

void Game::moveClouds()
{
	//spriteCloud1.setPosition(spriteCloud1.getPosition().x+ GetRandomNumber(1,9)*dt.asMilliseconds(), 340);
	spriteCloud1.setPosition(spriteCloud1.getPosition().x + 0.05, 0);
	spriteCloud2.setPosition(spriteCloud2.getPosition().x + 0.07, 100);
	spriteCloud3.setPosition(spriteCloud3.getPosition().x + 0.02, 150);
	if (spriteCloud1.getPosition().x > 1920)
	{
		spriteCloud1.setPosition(0, 340);
	}

}

void Game::moveBeeLeft()
{
	spriteBee.setPosition(spriteBee.getPosition().x - 0.5, 400);
	if (spriteBee.getPosition().x < 0)
	{
		textureBee.loadFromFile("graphics\\bee_right.png");
		isBeeMovingLeft = false;
		//spriteBee.setPosition(1920, 400);
	}
}

void Game::moveBeeRight()
{
	spriteBee.setPosition(spriteBee.getPosition().x + 0.5, 400);
	if (spriteBee.getPosition().x > 1920)
	{
		textureBee.loadFromFile("graphics\\bee_left.png");
		isBeeMovingLeft = true;

		//spriteBee.setPosition(1920, 400);
	}
}

void Game::createScoreText()
{
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	scoreText.setFont(font);

	scoreText.setString("Score = 0");

	scoreText.setCharacterSize(100);

	scoreText.setFillColor(Color::White);

	scoreText.setPosition(20, 20);
}

int Game::GetRandomNumber(int start, int end)
{
	int result;
	srand((unsigned)time(0));
	result = (rand() % end) + start;
	
	return result;

}

Game::~Game()
{
	//delegate this;
}