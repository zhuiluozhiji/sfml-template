#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    srand(time(NULL));
    // create the window
    RenderWindow window(VideoMode(800, 600), "My window");
    window.setFramerateLimit(60); // limit the frame rate to 60 FPS


    RectangleShape rect;
    rect.setFillColor(Color::White);
    rect.setSize(Vector2f(100.f, 50.f));
    rect.setOrigin(50.f, 25.f);

    CircleShape circle;
    circle.setFillColor(Color::Green);
    circle.setRadius(100.f);
    circle.setOrigin(100.f, 100.f);//先设置好基准点后才能setPosition 顺序反了会报错
    circle.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }
//UPDATE
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            rect.move(0.f, -5.f);
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            rect.move(0.f, 5.f);
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            rect.move(-5.f, 0.f);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            rect.move(5.f, 0.f);
        }

        if(Keyboard::isKeyPressed(Keyboard::R)){
            rect.rotate(10.f);
        }
        if(rect.getGlobalBounds().intersects(circle.getGlobalBounds()))
        {
            rect.setFillColor(Color::Red);
        }
        else
        {
            rect.setFillColor(Color::White);
        }
        // clear the window with black color
        window.clear(Color::Black);

        window.draw(rect);
        window.draw(circle);

        window.display();
    }

    return 0;
}