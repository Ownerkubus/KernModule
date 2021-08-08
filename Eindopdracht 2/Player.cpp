#include "Player.h"

Player::Player() {

    if (!playerTexture.loadFromFile("../assets/Fish.png")) {
        std::cout << "Kan vis texture niet laden";
    }

    SetSize(sizeX, sizeY);
    SetPos({screenWidth/2, screenHeight-75});
}

sf::RectangleShape Player::Draw(float dt) {

    speler.setSize(sf::Vector2f(80, 80));
    speler.setTexture(&playerTexture);

    return speler;
}

void Player::Move(float dt) {
    // Acceleration Physics Van Wridzer
    float acceleration = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed((sf::Keyboard::A)))
    {
        acceleration += this->playerSpeedX * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed((sf::Keyboard::D)))
    {
        acceleration -= this->playerSpeedX * dt;
    }

    this->velocity = (1 / this->frictionCoef) * (std::pow(2.71828,-this->frictionCoef / this->mass * dt)) *
                     (this->frictionCoef * this->velocity + this->mass * acceleration) - (this->mass * acceleration / this->frictionCoef);
    this->Position += Vector2(this->velocity, 0);

    this->speler.setPosition(sf::Vector2f(this->Position.GetX(), this->Position.GetY()));
    BorderCheck();
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

void Player::BorderCheck() {
    if (Position.GetX() > 1550)
    {
        SetPos({50, screenHeight - 75});

    }
    if (Position.GetX() < (0.f - 50 * 2))
    {
        SetPos({screenWidth - 50, screenHeight - 75});
    }
}
