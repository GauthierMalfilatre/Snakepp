#ifndef SNAKE_PART_HPP
    #define SNAKE_PART_HPP
    #include "main.hpp"
    #include "Snake.hpp"

class SnakePart {
public:
    SnakePart(float posx, float posy);
    ~SnakePart();

    const sf::Vector2f& getPos() const;
    void setPos(const sf::Vector2f& newPos);

    void moveBy(sf::Vector2f);

    const sf::RectangleShape& getShape() const;
    void setShapeColor(sf::Color color);
    void setShapeSize(const sf::Vector2f& newSize);

private:
    sf::Vector2f pos;
    sf::RectangleShape shape;
};

#endif
