#include "Player.h"

Player::Player() {
//    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("C:\\Users\\Ruben\\CLionProjects\\Eindopdracht\\assets\\Fish.png")) {
        std::cout << "Kan vis texture niet laden";
    }

    SetSize(sizeX, sizeY);
    SetPos({screenWidth/2, screenHeight-75});
//    sf::RectangleShape player;
//    player.setTexture(playerTexture);


}

sf::RectangleShape Player::Draw(float dt) {

//    Move(dt);
//    sf::RectangleShape speler;
    speler.setSize(sf::Vector2f(80, 80));
    speler.setTexture(&playerTexture);

    return speler;
}

void Player::Move(float dt) {

//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//    {
////            playerSprite.scale(sf::Vector2f(-0.2, -0.2));
//        speler.move(-playerSpeed * 0.2, 0.f);
////            playerSprite.scale(sf::Vector2f(-0.2, 0.2));
//    }
//
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//        //playerSprite.scale(sf::Vector2f(0.2, 0.2));
//        speler.move(playerSpeed * 0.2, 0.f);
//    }

    // Acceleration Physics Van Wridzer
    float acceleration = 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed((sf::Keyboard::A)))
    {
        acceleration += this->playerSpeedX * dt;
        std::cout << dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed((sf::Keyboard::D)))
    {
        acceleration -= this->playerSpeedX * dt;
    }

    this->velocity = (1 / this->frictionCoef) * (std::pow(2.71828,-this->frictionCoef / this->mass * dt)) *
                     (this->frictionCoef * this->velocity + this->mass * acceleration) - (this->mass * acceleration / this->frictionCoef);
    this->Position += Vector2(this->velocity, 0);


    this->speler.setPosition(sf::Vector2f(this->Position.GetX(), this->Position.GetY()));

}

Vector2 Player::GetPos(){
    return Position;
}

void Player::SetPos(Vector2 NewPos){
    Position = NewPos;
    speler.setPosition(sf::Vector2f(Position.GetX(), Position.GetY()));
}

Vector2 Player::GetSize()
{
    return Vector2(sizeX, sizeY);
}
void Player::SetSize(float _sizeX, float _sizeY)
{
    this->sizeX = _sizeX;
    this->sizeY = _sizeY;
    this->speler.setSize(sf::Vector2f(this->sizeX, this->sizeY));
}
