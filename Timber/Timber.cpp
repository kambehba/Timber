#include "Game.h"

using namespace sf;
void ProcessGame();

void MoveBee();
void MoveCloud1();
void MoveCloud2();
bool isBeeActive = false;
bool isCloud1Active = false;          
bool isCloud2Active = false;
bool isCloud3Active = false;
bool isGamePaused = true;
Sprite spriteBackground;
Sprite spriteTree;
float beeSpeed = 0.0f;
float cloud1Speed = 0.0f;
float cloud2Speed = 0.0f;
float cloud3Speed = 0.0f;
Texture textureBee;
Sprite spriteBee;
Texture textureTree;
Texture textureCloud;
Sprite spriteCloud1;
Sprite spriteCloud2;
Sprite spriteCloud3;

int score = 0;
sf::Text messageText;
sf::Text scoreText;
sf:: Font font;


Time dt;

int main()
{
    Game game;
    game.startGame();

    return 0;
    
    /*Time Bar - Strat*/
    RectangleShape timeBar;
    float timeBarStartWidth = 400;
    float timeBarHeight = 80;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
    
    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;




    /*Time Bar - End*/

    font.loadFromFile("fonts/KOMIKAP_.ttf");
    messageText.setFont(font);
    scoreText.setFont(font);

    messageText.setString("Press Enter to Start!");
    scoreText.setString("Score = 0");

    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);

    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);

    FloatRect textRect = messageText.getGlobalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
    scoreText.setPosition(20, 20);


    
    Texture textureBackground;

    textureBackground.loadFromFile("graphics/background.png");

    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    //Make the tree

    textureTree.loadFromFile("graphics/tree.png");

    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);


    //Prepare the bee

    textureBee.loadFromFile("graphics/bee.png");

    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    bool beeActive = false;
    float beeSpeed = 0.0f;

    //Make 3 cloud sprites from 1 texture

    textureCloud.loadFromFile("graphics/cloud.png");

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
   
    
    
    srand((int)time(0));
    int number = (rand() % 100);

    //while (window.isOpen())
    //{
    //  
    //    ProcessGame();
    //}

    return 0;
}



void ProcessGame()
{
    if (Keyboard::isKeyPressed(Keyboard::Enter))
    {
        isGamePaused = false;
     
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
       // window.close();
        //return 0;
    }

   // window.clear();

   // window.draw(spriteBackground);
   // window.draw(spriteCloud1);
  //  window.draw(spriteCloud2);
  //  window.draw(spriteCloud3);

  //  window.draw(spriteTree);
  //  window.draw(spriteBee);
  //  window.draw(scoreText);
  //  window.draw(messageText);

  //  window.display();

   
    if (!isGamePaused)
    {
      
        //Measure time
      //  dt = clock.restart();

        messageText.setString(" ");

        
        MoveBee();
        MoveCloud1();
        MoveCloud2();

        std::stringstream ss;

        ss << "Score = " << score;
        //scoreText.setString(ss.str());

    }

   // window.draw(scoreText);


  //  window.draw(messageText);
  

    //window.draw(spriteBee);
    //window.draw(spriteCloud1);
    //window.draw(spriteCloud2);

}

void MoveBee()
{
    if (!isBeeActive)
    {
        srand((int)time(0) * 10);
        beeSpeed = (rand() % 21);

        float height = (rand() % 500) + 500;
        spriteBee.setPosition(2000, height);
        isBeeActive = true;
    }
    else
    {
        spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asMicroseconds()), spriteBee.getPosition().y);
        int j = spriteBee.getPosition().x;
        if (spriteBee.getPosition().x < -100)
        {
            isBeeActive = false;
        }

    }

}

void MoveCloud1()
{
    if (!isCloud1Active)
    {
        srand((int)time(0) * 10);
        cloud1Speed = (rand() % 21);

        srand((int)time(0) * 10);
        float height = (rand() % 150);
        spriteCloud1.setPosition(-200, height);
        isCloud1Active = true;
    }
    else
    {
        spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asMicroseconds()), spriteCloud1.getPosition().y);
        int j = spriteCloud1.getPosition().x;
        if (spriteCloud1.getPosition().x > 1920)
        {
            isCloud1Active = false;
        }

    }

}

void MoveCloud2()
{
    if (!isCloud2Active)
    {
        srand((int)time(0) * 8);
        cloud2Speed = (rand() % 10);

        srand((int)time(0) * 20);
        float height = (rand() % 300);
        spriteCloud2.setPosition(-200, height);
        isCloud2Active = true;
    }
    else
    {
        spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asMicroseconds()), spriteCloud2.getPosition().y);
        int j = spriteCloud2.getPosition().x;
        if (spriteCloud2.getPosition().x > 1920)
        {
            isCloud2Active = false;
        }

    }

}






