#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    // create the window
    RenderWindow window(VideoMode(600, 400), "My window");
    window.setFramerateLimit(60); // limit the frame rate to 60 FPS

    CircleShape hoop;
    int dir = 0;
    hoop.setRadius(50.f);
    hoop.setFillColor(Color::Black);
    hoop.setOutlineThickness(2);
    hoop.setOutlineColor(Color::Blue);
    hoop.setPosition(Vector2f(0,10.f));

    CircleShape ball;
    bool isShot = false;
    ball.setRadius(20.f);
    ball.setFillColor(Color::Red);
    ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius()*3));

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
            if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }

        // Update hoop 
        if(hoop.getPosition().x <= 0)
            dir = 1;
        else if (hoop.getPosition().x + hoop.getRadius()*2 >= window.getSize().x)
            dir = 0;


        if(dir == 1){
            hoop.move(8.f, 0.f);
        } else {
            hoop.move(-8.f, 0.f);
        }

        //Update ball 
        if(Mouse::isButtonPressed(Mouse::Left))
            isShot = true;

        if(!isShot)
            ball.setPosition(Mouse::getPosition(window).x - ball.getRadius(), window.getSize().y - ball.getRadius()*3);
        else
            ball.move(0.f, -5.f);

        //Collision ball
        if(ball.getPosition().y <= 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds())){
            //Reset ball
            isShot = false;
            //ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius()*3));
        }



        window.clear(Color::White);

        // draw everything here...
        window.draw(hoop);
        window.draw(ball);

        // end the current frame
        window.display();
    }

    return 0;
}