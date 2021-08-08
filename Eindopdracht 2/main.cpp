#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#include "DeltaTime.h"
#include <vector>
#include <sstream>
#include "Player.h"

Player player = Player();

int main()
{
    DeltaTime* deltaTime = new DeltaTime();

    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("../assets/Shark.png")) {
        std::cout << "Kan shark texture niet laden";
    }

    int screenWidth = 1600;
    int screenHeight = 800;
    int enimNumber = 7;
    int score = 0;
    bool gameOver = false;
    int dodgedEnemies = 0;
    int dodgedEnemiesExtra = 0;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Fishy Sharks");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../assets/Background.png")) {
        std::cout << "Kan background texture niet laden";
        return 0;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.scale(sf::Vector2f(0.8, 0.55));

    //Create enemy
    std::vector<Enemy*> enimList;
    for (int i = 0; i < enimNumber; ++i) {
        Enemy* enemy = new Enemy(&enemyTexture);
        enimList.push_back(enemy);
    }

    sf::Font font;
    if (!font.loadFromFile("../assets/Fish.ttf"))
    {
        std::cout << "Kan font niet laden";
    }

    //Lives text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Lives: 3");
    scoreText.setCharacterSize(48);
    scoreText.setFillColor(sf::Color::Red);

    //Game over text
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("You died, click to play again!");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(500, 400);

    //Dodged enemies text
    sf::Text dodgedText;
    dodgedText.setFont(font);
    dodgedText.setCharacterSize(48);
    dodgedText.setFillColor(sf::Color::Red);
    dodgedText.setPosition(500, 500);

    while (window.isOpen())
    {
        deltaTime->UpdateDT();

        if (enimList.size() < enimNumber)
        {
            Enemy* enemy = new Enemy(&enemyTexture);
            enimList.push_back(enemy);
        }

        window.draw(backgroundSprite);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.Move(deltaTime->dt);

        for (int i = 0; i < enimList.size(); i++) {
            //Draw enemy
            if(gameOver == false) {
                window.draw(enimList[i]->Draw(deltaTime->dt));
            }
            //Delete enemy under the screen
            if(enimList[i]->BottomCheck())
            {
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
                dodgedEnemies++;
                dodgedEnemiesExtra++;
                if(dodgedEnemiesExtra == 15){
                    dodgedEnemiesExtra = 0;
                    enimNumber++;
                }
            }

            bool collisionX = player.GetPos().GetX() + player.GetSize().GetX() >= enimList[i]->GetPos()->GetX() &&
                              enimList[i]->GetPos()->GetX() + enimList[i]->GetSize().GetX() >= player.GetPos().GetX();

            bool collisionY = player.GetPos().GetY() + player.GetSize().GetY() >= enimList[i]->GetPos()->GetY() &&
                              enimList[i]->GetPos()->GetY() + enimList[i]->GetSize().GetY() >= player.GetPos().GetY();

            if(collisionX && collisionY){
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
                score++;
                std::cout << score;
                if(score == 1){
                    scoreText.setString("Lives: 2");
                }else if(score == 2){
                    scoreText.setString("Lives: 1");
                }else if(score == 3){
                    scoreText.setString("Lives: 0");
                    gameOver = true;
                }

            }
        }

        if(gameOver == true){
            window.draw(gameOverText);
            std::string String = static_cast<std::ostringstream*>( &(std::ostringstream() << dodgedEnemies) )->str();
            dodgedText.setString("Your score is "+String);
            window.draw(dodgedText);

            for (int i = 0; i < enimList.size(); i++){
                delete enimList[i];
                enimList.erase(enimList.begin() + i);
            }

            player.SetPos({800, 725});

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                gameOver = false;
                score = 0;
                dodgedEnemies = 0;
                scoreText.setString("Lives: 3");
            }

        }
        window.draw(scoreText);
        if(gameOver == false) {
            window.draw(player.Draw(0));
        }
        window.display();
        window.clear();
    }

    return 0;
}