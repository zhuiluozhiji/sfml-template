#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(800, 600), "Cat doge");
    window.setFramerateLimit(60); // limit the frame rate to 60 FPS


//CAT
    Texture catTex;
    Sprite cat;
    int hp = 10;
    RectangleShape hpBar;
    hpBar.setSize(Vector2f((float)hp * 20.f, 20.f));
    hpBar.setFillColor(Color::Red);
    hpBar.setPosition(200.f, 10.f);

    //if(!catTex.loadFromFile("/home/man567/code/sfml-template/Textures/cat.png"))
    if (!catTex.loadFromFile("Textures/cat11.png"))
        throw "Could not load cat texture";

    cat.setTexture(catTex);
    cat.setScale(0.1f, 0.1f); // scale the cat sprite to half its size

    vector<Sprite> cats;
    cats.push_back(cat);
    int catSpawnTimer = 20;

//DOGE
    Texture dogeTex;
    Sprite doge;

    if (!dogeTex.loadFromFile("Textures/doge.png"))
        throw "Could not load doge texture";

    doge.setTexture(dogeTex);
    doge.setScale(0.04f, 0.04f); // scale the doge sprite to half its size

//GAME LOOP
    while (window.isOpen() && hp > 0) // game loop runs while the window is open and the player has health
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
            if( event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) // if the escape key is pressed
            {
                window.close(); // close the window
            }
        }
//UPDATE
//cat(enemies)
        for(size_t i = 0; i < cats.size(); ++i)
        {
             cats[i].move(-10.f, 0.f); // move each cat sprite slightly
            if(cats[i].getPosition().x < 0 - cats[i].getGlobalBounds().width) // if the cat goes off screen
            {
                cats.erase(cats.begin() + i); // remove the cat if it goes off screen
            }
        }
        if(catSpawnTimer < 10)
        {
            catSpawnTimer++;
        }
        else
        {
            cat.setPosition(window.getSize().x, rand() % int(window.getSize().y - cat.getGlobalBounds().height)); // spawn at a random height
            cats.push_back(cat);
            catSpawnTimer = 0;
        }


//DOGE(player)
        doge.setPosition(doge.getPosition().x, Mouse::getPosition(window).y);
        if(doge.getPosition().y < 0) // if the doge goes off screen
        {
            doge.setPosition(doge.getPosition().x, 0); // set the doge's position to the top of the screen
        }
        if(doge.getPosition().y > window.getSize().y - doge.getGlobalBounds().height) // if the doge goes off screen
        {
            doge.setPosition(doge.getPosition().x, window.getSize().y - doge.getGlobalBounds().height); // set the doge's position to the top of the screen
        }

//COLLISION
        for(size_t i = 0; i < cats.size(); ++i)
        {
            if(cats[i].getGlobalBounds().intersects(doge.getGlobalBounds())) // if the cat collides with the doge
            {   
                hp--;
                cats.erase(cats.begin() + i); // remove the cat
                 
            }
        }


//UI
        hpBar.setSize(Vector2f((float)hp * 20.f, 20.f));

//DRAW
        window.clear(Color::Black);
        window.draw(doge);
        for(size_t i = 0; i < cats.size(); ++i)
        {
            window.draw(cats[i]);
        }
        window.draw(hpBar);
        window.display();
    }

    return 0;
}