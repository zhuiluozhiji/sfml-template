#include <SFML/System/Vector2.hpp>
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
    //window.setFramerateLimit(60); // limit the frame rate to 60 FPS
    //dt at 60 FPS is 1/60 = 0.016 seconds
    Clock clock;
    float dt;
    float multiplier = 60.f;

    RectangleShape shape(Vector2f(50.f, 50.f));
    shape.setFillColor(Color::White);

    Vector2f currentVelocity;
    Vector2f direction;
    float maxVelocity = 25.f;
    float acceleration = 1.f;
    float drag = 0.5f;




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
//UPDATE
//acceleration
        direction = Vector2f(0.f,0.f); 
        
        if(Keyboard::isKeyPressed(Keyboard::A))
        {
            direction.x = -1.f;
            if(currentVelocity.x > -maxVelocity)
            {
                currentVelocity.x += acceleration * direction.x * dt * multiplier;
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::D))
        {
            direction.x = 1.f;
            if(currentVelocity.x < maxVelocity)
            {
                currentVelocity.x += acceleration * direction.x * dt * multiplier;
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::W))
        {
            direction.y = -1.f;
            if(currentVelocity.y > -maxVelocity)
            {
                currentVelocity.y += acceleration * direction.y * dt * multiplier;
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::S))
        {
            direction.y = 1.f;
            if(currentVelocity.y < maxVelocity)
            {
                currentVelocity.y += acceleration * direction.y * dt * multiplier;
            }
        }
//drag
        if(currentVelocity.x > 0.f)
        {
            currentVelocity.x -= drag * dt * multiplier;
            if(currentVelocity.x < 0.f) currentVelocity.x = 0.f;
        }
        else if (currentVelocity.x < 0.f)
        {
            currentVelocity.x += drag * dt * multiplier;
            if(currentVelocity.x > 0.f) currentVelocity.x = 0.f;
        }
        if(currentVelocity.y > 0.f)
        {
            currentVelocity.y -= drag * dt * multiplier;
            if(currentVelocity.y < 0.f) currentVelocity.y = 0.f;
        }
        else if (currentVelocity.y < 0.f)
        {
            currentVelocity.y += drag * dt * multiplier;
            if(currentVelocity.y > 0.f) currentVelocity.y = 0.f;
        }
        shape.move(currentVelocity * dt * multiplier); // move the shape based on current velocity
        // clear the window with black color
        window.clear(Color::Black);

        window.draw(shape); // draw the rectangle shape


        window.display();

        cout << "Delta time: " << dt << " seconds" << endl;
    }

    return 0;
}