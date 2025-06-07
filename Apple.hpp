#ifndef APPLE_H
    #define APPLE_H
    #include "main.hpp"

class Apple {
public:
    Apple();
    ~Apple();
    const sf::Vector2f& getPos() const;
    void spawn();
    void spawnTo(const float x, const float y);
    void render(sf::RenderWindow& window) const;

private:
    sf::Vector2f pos;
    sf::RectangleShape shape;
};

#endif
