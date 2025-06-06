#include "Snake.hpp"
#include "SnakePart.hpp"

Snake::Snake(std::string name, sf::Vector2i startingHeadPos, unsigned int startingLength) : name(name), length(startingLength), direction(0.f, -1.f) {
    if (this->length <= 0) {
        this->length = 3;
    }
    for (int i = 0; i < this->length; i++) {
        this->body.push_back(SnakePart(startingHeadPos.x / 20, startingHeadPos.y / 20 + i));
        this->body[i].setShapeColor(sf::Color::Green);
        this->body[i].setShapeSize(sf::Vector2f(20.f, 20.f));
    }
}

Snake::~Snake() {}

int Snake::getScore() const {
    return this->score;
}

void Snake::increaseScore(int ammount) {
    this->score++;
}

void Snake::update() {
    this->delta_t = this->clock.restart().asMilliseconds();

    sf::Vector2f previousPos = this->body[0].getPos();
    this->body[0].moveBy(this->direction);
    for (int i = 1; i < this->body.size(); i++) {
        sf::Vector2f tempPreviousPos = this->body[i].getPos();
        this->body[i].setPos(previousPos);
        previousPos = tempPreviousPos;
    }
}

void Snake::render(sf::RenderWindow& window) const {
    for (int i = 0; i < this->body.size(); i++) {
        window.draw(this->body[i].getShape());
    }
}

void Snake::augmente(int ammount)
{
    for (int i = 0; i < ammount; i++) {
        this->body.push_back(body.back());
    }
}

void Snake::changeDir(float x, float y)
{
    this->direction.x = x;
    this->direction.y = y;
}

int Snake::getLength() const {
    return this->length;
}

const std::string& Snake::getName() const {
    return this->name;
}
