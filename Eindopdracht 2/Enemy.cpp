#include "Enemy.h"

Enemy::Enemy(const sf::Texture* enemyTexture) {
    position = new Vector2(posX, posY);

    if(randomFloat == 1){
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
    vijand.setTexture(enemyTexture);
    SetSize(sizeX, sizeY);
}

Enemy::~Enemy() {

}

void Enemy::Move(float dt) {
    float accelerationX = 0;
    float accelerationY = 0;
    if (fallSpeed <= minSpeed)
    {
        fallSpeed = rand() % 20;
    }
    if (moveSpeed == 0)
    {
        moveSpeed = rand() % 20;
    }
    accelerationX += moveSpeed * dt;
    accelerationY += fallSpeed * dt;
    velocityX = (1/frictionCoef) * (std::pow(2.71828,-frictionCoef/mass*dt))*(frictionCoef*velocityX+mass*accelerationX)-(mass*accelerationX/frictionCoef);
    velocityY = (1/frictionCoef) * (std::pow(2.71828,-frictionCoef/mass*dt))*(frictionCoef*velocityY+mass*accelerationY)-(mass*accelerationY/frictionCoef);
    Vector2* move = new Vector2(velocityX,-velocityY);
    *position = *position + *move;
    BorderCheck();
}

sf::RectangleShape Enemy::Draw(float dt) {

    Move(dt);
    vijand.setSize(sf::Vector2f(150, 100));
    vijand.setPosition(position->GetX(), position->GetY());
    return vijand;
}

void Enemy::BorderCheck() {
    if (position->GetX() > 1600)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
    if (position->GetX() < 0.f)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
}

bool Enemy::BottomCheck()
{
    if (position->GetY() > 805)
    {
        return true;
    }
}

Vector2* Enemy::GetPos(){
    return position;
}

Vector2 Enemy::GetSize()
{
    return Vector2(sizeX, sizeY);
}
void Enemy::SetSize(float _sizeX, float _sizeY)
{
    this->sizeX = _sizeX;
    this->sizeY = _sizeY;
    this->vijand.setSize(sf::Vector2f(this->sizeX, this->sizeY));
}