#include "main.hpp"
#include "Apple.hpp"
#include <random>

Apple::Apple() {
    this->shape.setSize(sf::Vector2f(20.f, 20.f));
    this->shape.setFillColor(sf::Color::Red);
}

Apple::~Apple() {}

const sf::Vector2f& Apple::getPos() const {
    return this->pos;
}

void Apple::spawn() {
    this->pos.x = rand() % (WIN_W / 20);
    this->pos.y = rand() % (WIN_H / 20);
    this->shape.setPosition(sf::Vector2f(this->pos.x * 20.f, this->pos.y * 20.f));
}

void Apple::spawnTo(const float x, const float y) {
    this->pos.x = x / 20.f;
    this->pos.y = y / 20.f;
    this->shape.setPosition(sf::Vector2f(this->pos.x * 20.f, this->pos.y * 20.f));
}

void Apple::render(sf::RenderWindow& window) const {
    window.draw(this->shape);
}
