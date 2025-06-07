#include "main.hpp"
#include "Apple.hpp"

static void keyboard(Snake &snake)
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

static void check_collisions(Snake &snake, Apple &apple)
{
    sf::Vector2f snakePos = snake.getHeadPos();
    sf::Vector2f applePos = apple.getPos();

    if (snakePos.x == applePos.x && snakePos.y == applePos.y) {
        snake.increaseScore();
        snake.augmente();
        apple.spawn();
    }
}

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(WIN_W, WIN_H), "SFML window");
    Snake *snake = new Snake("Maxence", sf::Vector2i(WIN_W / 2, WIN_H / 2));
    Apple *apple = new Apple();

    srand(time(NULL));
    apple->spawn();
    while (window.isOpen()) {
        sf::Event evt;
        while (window.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed) {
                window.close();
            }
            keyboard(*snake);
        }
        window.clear(sf::Color(22, 22, 22));
        snake->update(*apple);
        check_collisions(*snake, *apple);
        snake->render(window);
        apple->render(window);
        window.display();
    }
    delete apple;
    delete snake;
}
