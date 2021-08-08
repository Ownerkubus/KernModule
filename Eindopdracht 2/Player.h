#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"

class Player {
public:
    Player();
    void Move(float dt);
    void BorderCheck();
    sf::RectangleShape Draw(float dt);
    sf::RectangleShape speler;
    Vector2 GetPos();
    void SetPos(Vector2 NewPos);

    Vector2 GetSize();

    void SetSize(float _sizeX, float _sizeY);

private:
    float playerSpeedX = 800;
    float screenWidth = 1600;
    float screenHeight = 800;
    float sizeX = 50;
    float sizeY = 50;
    Vector2 Position = Vector2(0, 0);

    sf::Texture playerTexture;

    float velocity;
    float frictionCoef = 0.6;
    float mass = 1;
};