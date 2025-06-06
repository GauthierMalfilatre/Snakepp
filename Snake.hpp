#ifndef SNAKE_HPP
    #define SNAKE_HPP
    #include "main.hpp"

class SnakePart;

class Snake {
public:
    Snake(std::string name, sf::Vector2i startingHeadPos, unsigned int startingLength = 3);
    ~Snake();

    sf::Vector2i getPos() const;
    const std::string& getName() const;
    int getLength() const;
    int getScore() const;

    void increaseScore(int amount = 1);
    void update();
    void render(sf::RenderWindow& window) const;

    void changeDir(float x, float y);
    void augmente(int ammount = 1);

private:
    sf::Clock clock;
    float delta_t;
    sf::RectangleShape shape;
    unsigned int length;
    int score;
    sf::Vector2f direction;
    std::string name;
    std::vector<SnakePart> body;
};

#endif
