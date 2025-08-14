#include <iostream>
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
    Font font;
    if(!font.loadFromFile("Fonts/weiruanyahei.ttf"))
        throw("COULD NOT LOAD FONT");


    Text text;
    text.setFont(font);
    text.setString("Hello, SFML!");
    text.setCharacterSize(24);
    text.setFillColor(Color::White);
    text.setStyle(Text::Bold);

    Font cfont;
    if(!cfont.loadFromFile("Fonts/huawenfangsong.ttf"))
        throw("COULD NOT LOAD FONT");
    Text ctext;
    ctext.setPosition(0.f,200.f);
    ctext.setFont(cfont);
    ctext.setString("华文仿宋");
    ctext.setCharacterSize(24);
    ctext.setFillColor(Color::Yellow);
    ctext.setStyle(Text::Bold);

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

        // clear the window with black color
        window.clear(Color::Black);

        window.draw(text); // draw the text
        window.draw(ctext); // draw the Chinese text

        // end the current frame
        window.display();
    }

    return 0;
}