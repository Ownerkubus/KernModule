#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"

class Enemy {
public:
    Enemy(int windowW);
    ~Enemy();
    void Move(float dt);
    sf::RectangleShape Draw(float dt);
    void BorderCheck();
    Vector2* position;
    float velocityX;
    float velocityY;
    float frictionCoef = 0.6;
    float mass = 0.003;
    int enimSize = 10;
    sf::RectangleShape vijand;

    Vector2 GetPos();
    void SetPos(Vector2 NewPos);

    Vector2 GetSize();
    float sizeX = 1;
    float sizeY = 1;

    void SetSize(float _sizeX, float _sizeY);


private:
    int wW;
    float posX = rand() % 1600;
    float posY = -10;
    float moveSpeed = rand() % 10;
    float fallSpeed = rand() % 10;
    float minSpeed = 10;

    sf::Texture enemyTexture;

    Vector2 Position = Vector2(0, 0);
};