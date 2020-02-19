#include "Game.h"
using namespace sf;

Game::Game() 
{
	setWindow();
	setBackground();
	
}

void Game::startGame()
{
	while (true)
	{
		window.clear();
		window.draw(spriteBackground);
		window.display();
		

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
			return;
		}
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