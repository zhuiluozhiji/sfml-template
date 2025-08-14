#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;


class Bullet
{
public:
    CircleShape shape;
    Vector2f currVelocity;
    float maxSpeed;

    Bullet(float radius = 5.f) : currVelocity(0.f,0.f), maxSpeed(15.f)
    {
        shape.setRadius(radius);
        shape.setFillColor(Color::Red);
        
    }

};

int main()
{
    srand(time(NULL));
    // create the window
    RenderWindow window(VideoMode(800, 600), "My window");
    window.setFramerateLimit(60); // limit the frame rate to 60 FPS
//player
    CircleShape player(25.f);
    player.setFillColor(Color::White);

//bullets
    Bullet b1;
    vector<Bullet> bullets;


//vectors
    Vector2f playerCenter;
    Vector2f mousePosWindow;
    Vector2f aimDir;
    Vector2f aimDirNorm;

//enemy
    RectangleShape enemy;
    enemy.setSize(Vector2f(50.f, 50.f));
    enemy.setFillColor(Color::Magenta);
    vector<RectangleShape> enemies;
    int enemySpawnTimer = 0;

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
//vectors
        playerCenter = player.getPosition() + Vector2f(player.getRadius(), player.getRadius());
        mousePosWindow = Vector2f(Mouse::getPosition(window));
        aimDir = mousePosWindow - playerCenter;
        aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));

  //      cout << aimDirNorm.x << " " << aimDirNorm.y << endl;
  
//player
        if(Keyboard::isKeyPressed(Keyboard::A))
            player.move(-10.f, 0.f);
        if(Keyboard::isKeyPressed(Keyboard::D))
            player.move(10.f, 0.f);
        if(Keyboard::isKeyPressed(Keyboard::W))
            player.move(0.f, -10.f);
        if(Keyboard::isKeyPressed(Keyboard::S))
            player.move(0.f, 10.f);

//enemy
        if(enemySpawnTimer < 20)
        {
            enemySpawnTimer++;
        }
        if(enemySpawnTimer >= 20 && enemies.size() < 50) // spawn an enemy every 20 frames, max 10 enemies
        {
            enemy.setPosition(rand() % (window.getSize().x - static_cast<int>(enemy.getSize().x)),
                              rand() % (window.getSize().y - static_cast<int>(enemy.getSize().y)));
            enemies.push_back(enemy);
            enemySpawnTimer = 0;
        }


//shooting
        if(Mouse::isButtonPressed(Mouse::Left)){
            b1.shape.setPosition(playerCenter);
            b1.currVelocity = aimDirNorm * b1.maxSpeed;
            bullets.push_back(b1);
        }
        for(size_t i = 0; i < bullets.size(); ++i)
        {
            bullets[i].shape.move(bullets[i].currVelocity);

            //out of bounds
            if(bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > window.getSize().x ||
               bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
            {
                bullets.erase(bullets.begin() + i);
                --i; // adjust index after erasing
            }
            else{
            //collision
                for(size_t j = 0; j < enemies.size(); ++j)
                {
                    if(bullets[i].shape.getGlobalBounds().intersects(enemies[j].getGlobalBounds()))
                    {
                        bullets.erase(bullets.begin() + i);
                        enemies.erase(enemies.begin() + j);
                        --i; // adjust index after erasing
                        break;
                    }
                }
            }
        }
        cout << bullets.size() << endl;


        // clear the window with black color
        window.clear(Color::Black);

        // draw everything here...
        window.draw(player);
        for(size_t i = 0; i < bullets.size(); ++i)
        {
            // update bullet position

            window.draw(bullets[i].shape);
        }
        for(size_t i = 0; i < enemies.size(); ++i)
        {
            window.draw(enemies[i]);
        }

        // end the current frame
        window.display();
    }

    return 0;
}