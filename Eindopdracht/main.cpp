#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#include "DeltaTime.h"
#include <vector>
#include <sstream>
#include "Player.h"
#include "Collider.h"

Player player = Player();
Collider collider = Collider();

int main()
{
    DeltaTime* deltaTime = new DeltaTime();
    bool firstLoop = true;

    int screenWidth = 1600;
    int screenHeight = 800;
    //float deltaTime = 0.2;
    float playerSpeed = 0.5;
    int playerScaleX = 0.2;
    int playerScaleY = 0.2;
    int enimNumber = 4;
    int winScore = 14; //minus one
    int windowW = 1600;
    int windowH = 800;
    int frameCounter = 0;
    int secondsCounter = 0;

    std::cout << "Hello World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Fishy Sharks");
//    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
//    rectangle.setSize(sf::Vector2f(100, 50));
//    rectangle.setFillColor(sf::Color::Blue);
//    rectangle.setPosition(screenWidth/2, screenHeight - 75);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:\\Users\\Ruben\\CLionProjects\\Eindopdracht\\assets\\Background.png")) {
        std::cout << "Kan background texture niet laden";
        return 0;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.scale(sf::Vector2f(0.8, 0.55));

//    sf::Texture playerTexture;
//    if (!playerTexture.loadFromFile("C:\\Users\\Ruben\\CLionProjects\\Eindopdracht\\assets\\Fish.png")) {
//        std::cout << "Kan vis texture niet laden";
//        return 0;
//    }
////    sf::RectangleShape player;
////    player.setTexture(playerTexture);
//
//    sf::Sprite playerSprite;
//    playerSprite.setTexture(playerTexture);
//    playerSprite.scale(sf::Vector2f(0.2, 0.2));
//    playerSprite.setPosition(screenWidth/2, screenHeight-75);

    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("C:\\Users\\Ruben\\CLionProjects\\Eindopdracht\\assets\\Shark.png")) {
        std::cout << "Kan shark texture niet laden";
        return 0;
    }

//    sf::RectangleShape vijand;
//    vijand.setSize(sf::Vector2f(150, 100));
//    vijand.setTexture(&enemyTexture);
//    vijand.setTextureRect(sf::IntRect(10, 10, 100, 100));

//    sf::Sprite enemySprite;
//    enemySprite.setTexture(enemyTexture);
//    enemySprite.scale(sf::Vector2f(0.2, 0.2));

    //Create enemy
    std::vector<Enemy*> enimList;
    for (int i = 0; i < enimNumber; ++i) {
        Enemy* enemy = new Enemy(windowW);
        enimList.push_back(enemy);
    }

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\Ruben\\CLionProjects\\Eindopdracht\\assets\\Fish.ttf"))
    {
        std::cout << "Kan font niet laden";
    }
//    sf::Clock clock;
//
//    const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
//    sf::Text secondsText;
//    std::stringstream ss;
//    ss << secondsCounter;
//    secondsText.setString( ss.str().c_str() );
//
//    secondsText.setFont(font);
////    secondsText.setString("0");
//    secondsText.setCharacterSize(148);
//    secondsText.setFillColor(sf::Color::Red);

    //Lives text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Lives: 3");
    scoreText.setCharacterSize(48);
    scoreText.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        //set deltatime
        deltaTime->UpdateDT();

        window.draw(backgroundSprite);

        frameCounter++;
        if(frameCounter > 60){
            frameCounter = 0;
            secondsCounter++;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//        {
////            playerSprite.scale(sf::Vector2f(-0.2, -0.2));
//            playerSprite.move(-playerSpeed * 0.2, 0.f);
////            playerSprite.scale(sf::Vector2f(-0.2, 0.2));
//        }
//
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//        {
//            //playerSprite.scale(sf::Vector2f(0.2, 0.2));
//            playerSprite.move(playerSpeed * 0.2, 0.f);
//        }

        player.Move(deltaTime->dt);

        for (int i = 0; i < enimList.size(); ++i) {
            //Draw enemy
            window.draw(enimList[i]->Draw(deltaTime->dt));
            //Delete enemy under screen
            if(enimList[i]->Draw(deltaTime->dt).getPosition().y > windowH + 5)
            {
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
//                sm->Play("yoda.wav");
//                score->RetractScore(1);
            }
//            if(collider.isRectanglesColliding(enimList[i]->vijand, player.speler)) {
//                std::cout << "Collision!";
//                delete enimList[i];
//                enimList.erase(enimList.begin() + i);
//            }
            bool collisionX = player.GetPos().GetX() + player.GetSize().GetX() >= enimList[i]->GetPos().GetX() &&
                              enimList[i]->GetPos().GetX() + enimList[i]->GetSize().GetX() >= player.GetPos().GetX();

            bool collisionY = player.GetPos().GetY() + player.GetSize().GetY() >= enimList[i]->GetPos().GetY() &&
                              enimList[i]->GetPos().GetY() + enimList[i]->GetSize().GetY() >= player.GetPos().GetY();

            if(collisionX && collisionY){
                std::cout << "Collision!";
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
            }
        }

        //Add new enemies
        while (enimList.size() < enimNumber) {
            Enemy* enemy = new Enemy(windowW);
            enimList.push_back(enemy);
        }

//        window.draw(vijand);
//        window.draw(secondsText);
        window.draw(scoreText);
        window.draw(player.Draw(0));
//        window.draw(enemySprite);
//        window.draw(rectangle);
        window.display();
        window.clear();
    }

    return 0;
}