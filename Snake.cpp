#include "Snake.hpp"
#include "SnakePart.hpp"
#include "Apple.hpp"

Snake::Snake(std::string name, sf::Vector2i startingHeadPos, unsigned int startingLength) : name(name), length(startingLength), direction(0.f, -1.f) {
    if (this->length <= 0) {
        this->length = 3;
    }
    this->score = 0;
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

const sf::Vector2f& Snake::getHeadPos() const {
    return this->body[0].getPos();
}

void Snake::increaseScore(int ammount) {
    this->score++;
}

void Snake::update(Apple& apple) {
    if (this->clock.getElapsedTime().asMilliseconds() >= MAX(100.f - this->score * 2, 20.f)) {
        this->clock.restart();
    } else {
        return;
    }
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
    std::cout << "Score : " << this->score << std::endl;
}

void Snake::augmente(int ammount)
{
    for (int i = 0; i < ammount; i++) {
        this->body.push_back(body.back());
    }
    this->length++;
}

void Snake::changeDir(float x, float y)
{
    if (abs(this->direction.x) + abs(x) > 1 || abs(this->direction.y) + abs(y) > 1) {
        return;
    }
    this->direction.x = x;
    this->direction.y = y;
}

const sf::Vector2f& Snake::getDir() const {
    return this->direction;
}

int Snake::getLength() const {
    return this->length;
}

const std::string& Snake::getName() const {
    return this->name;
}
