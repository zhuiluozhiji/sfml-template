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
    
    RenderWindow window(VideoMode(800, 600), "My window");
    window.setFramerateLimit(60); 
//DEFINE
    


    while (window.isOpen())
    {
        
        Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == Event::Closed)
                window.close();
        }
//UPDATE
        



        window.clear(Color::Black);
//DRAW



        window.display();
    }

    return 0;
}