#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Отталкивание от стенок");

    sf::CircleShape circle(30.0f);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(100.0f, 100.0f);

    float velocityX = 5.0f;
    float velocityY = 5.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    
        circle.move(velocityX, velocityY);

        if (circle.getPosition().x < 0 || circle.getPosition().x + 2 * circle.getRadius() > window.getSize().x)
        {
            velocityX = -velocityX; 
        }
        if (circle.getPosition().y < 0 || circle.getPosition().y + 2 * circle.getRadius() > window.getSize().y)
        {
            velocityY = -velocityY; 
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
