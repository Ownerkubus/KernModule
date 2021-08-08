#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"

class Enemy {
public:
    Enemy(const sf::Texture* enemyTexture);
    ~Enemy();
    void Move(float dt);
    sf::RectangleShape Draw(float dt);
    void BorderCheck();
    Vector2* position;
    float velocityX;
    float velocityY;
    float frictionCoef = 0.6;
    float mass = 0.003;
    sf::RectangleShape vijand;

    Vector2* GetPos();

    Vector2 GetSize();
    float sizeX = 100;
    float sizeY = 50;

    void SetSize(float _sizeX, float _sizeY);

    bool BottomCheck();
private:
    float posX = rand() % 1500;
    float posY = -10;
    float moveSpeed = rand()%(45000-10000+1)+5000;;
    float fallSpeed = rand()%(50000-30000+1)+15000;
    float minSpeed = 1000;
    float randomFloat = rand()%2;
};