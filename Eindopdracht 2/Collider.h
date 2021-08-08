#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
//#include "main.cpp"

class Collider {
public:
    Collider();
    bool isRectanglesColliding(sf::RectangleShape vijand, sf::RectangleShape speler);
};