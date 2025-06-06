#include "SnakePart.hpp"
#include "main.hpp"

SnakePart::SnakePart(float posx, float posy) : pos(posx, posy) {
    this->shape.setPosition(sf::Vector2f(posx * 20.f, posy * 20.f));
}

SnakePart::~SnakePart() {};

void SnakePart::setPos(const sf::Vector2f& newPos) {
    this->pos.x = newPos.x;
    this->pos.y = newPos.y;
    this->shape.setPosition(sf::Vector2f(newPos.x * 20.f, newPos.y * 20.f));
}

void SnakePart::moveBy(sf::Vector2f offsets) {
    sf::Vector2f basePos = getPos();
    sf::Vector2f targetPos(basePos.x + offsets.x, basePos.y + offsets.y);
    setPos(targetPos);   
}

const sf::Vector2f& SnakePart::getPos() const {
    return this->pos;
}

const sf::RectangleShape& SnakePart::getShape() const {
    return this->shape;
}

void SnakePart::setShapeColor(sf::Color color) {
    this->shape.setFillColor(color);
}

void SnakePart::setShapeSize(const sf::Vector2f& newSize) {
    this->shape.setSize(newSize);
}
