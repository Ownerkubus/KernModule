#pragma once
#include <SFML/Graphics.hpp>


class DeltaTime {
public:
    float dt;
    sf::Clock clock;
    DeltaTime();
    ~DeltaTime();
    void UpdateDT();
};
