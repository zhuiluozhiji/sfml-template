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
    // create the window
    RenderWindow window(VideoMode(800, 600), "My window");
    window.setFramerateLimit(60); // limit the frame rate to 60 FPS

    Clock clock;
    float dt;
    float multiplier = 60.f;

    RectangleShape shape(Vector2f(50.f, 50.f));
    shape.setFillColor(Color::White);


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

        dt = clock.restart().asSeconds(); // get the time elapsed since the last frame
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            shape.move(-10.f * dt * multiplier, 0.f);
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            shape.move(10.f * dt * multiplier, 0.f);
        }

        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            shape.move(0.f, -10.f * dt * multiplier);
        }

        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            shape.move(0.f, 10.f * dt * multiplier);
        }

        // clear the window with black color
        window.clear(Color::Black);

        window.draw(shape); // draw the rectangle shape


        window.display();

        cout << "Delta time: " << dt << " seconds" << endl;
    }

    return 0;
}