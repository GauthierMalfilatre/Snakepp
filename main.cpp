#include "main.hpp"

static void keyboard(Snake& snake)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        snake.changeDir(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        snake.changeDir(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        snake.changeDir(0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        snake.changeDir(0, 1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        snake.augmente();
    }
}

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    Snake* snake = new Snake("Maxence", sf::Vector2i(800 / 2, 600 / 2));

    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window.close();
            }
            keyboard(*snake);
        }
        window.clear(sf::Color::Blue);
        snake->update();
        snake->render(window);
        window.display();
        window.setFramerateLimit(5);
    }
    delete snake;
}
