#include "Collider.h"

Collider::Collider() {

}

bool Collider::isRectanglesColliding(sf::RectangleShape vijand, sf::RectangleShape speler) {
    int topEdge1 = vijand.getPosition().y + vijand.getSize().y;
    int rightEdge1 = vijand.getPosition().x + vijand.getSize().x;
    int leftEdge1 = vijand.getPosition().x;
    int bottomEdge1 = vijand.getPosition().y;
    int topEdge2 = speler.getPosition().y + speler.getSize().y;
    int rightEdge2 = speler.getPosition().x + speler.getSize().x;
    int leftEdge2 = speler.getPosition().x;
    int bottomEdge2 = speler.getPosition().y;

    if (leftEdge1 < rightEdge2 && rightEdge1 > leftEdge2 && bottomEdge1 < topEdge2 && topEdge1 > bottomEdge2) {
        return true;
    }
    return false;
}
