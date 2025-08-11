#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <vector>
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
    RenderWindow window(VideoMode(800, 800), "BALL SHOOTING");
    window.setFramerateLimit(60); // limit the frame rate to 60 FPS


    CircleShape projectile;
    projectile.setRadius(5.f);
    projectile.setFillColor(Color::Red);

    RectangleShape enemy;
    enemy.setFillColor(Color::Magenta);
    enemy.setSize(Vector2f(50.f,50.f));
    int enemySpawnTimer = 0;

    CircleShape player;
    player.setFillColor(Color::White);
    player.setRadius(50.f);
    player.setPosition(window.getSize().x / 2 - player.getRadius(), window.getSize().y - player.getRadius() * 2 - 10.f);
    Vector2f playerCenter ;
    int shootTimer = 0;


    vector<CircleShape> projectiles;
    projectiles.push_back(projectile);
    vector<RectangleShape> enemies;
    enemies.push_back(enemy);



    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

//player
    
        playerCenter = player.getPosition() + Vector2f(player.getRadius(), player.getRadius());
        if(shootTimer < 5){
            shootTimer++;
        }
        player.setPosition(Mouse::getPosition(window).x - player.getRadius(), player.getPosition().y);

//projectile
        if(Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 5){
            projectile.setPosition(playerCenter);
            projectiles.push_back(projectile);

            shootTimer = 0;
        }

        for(size_t i = 0; i < projectiles.size(); i++){
            projectiles[i].move(0.f, -10.f);
            if(projectiles[i].getPosition().y <= 0){
                projectiles.erase(projectiles.begin() + i);
            }
        }

//enemy
        if(enemySpawnTimer < 20){
            enemySpawnTimer++;
        } 
        else {
            enemy.setPosition(rand() % (window.getSize().x - (int)enemy.getSize().x), 0.f);
            enemies.push_back(enemy);
            enemySpawnTimer = 0;
        }
        for(size_t i = 0; i < enemies.size(); i++){
            enemies[i].move(0.f, 5.f);
            if(enemies[i].getPosition().y >= window.getSize().y){
                enemies.erase(enemies.begin() + i);
            }

        }
//collision detection
        if(!projectiles.empty() && !enemies.empty()){
            for(size_t i = 0; i < enemies.size(); i++){
                for(size_t k = 0;k < projectiles.size();k++){
                    if(enemies[i].getGlobalBounds().intersects(projectiles[k].getGlobalBounds())){
                        enemies.erase(enemies.begin() + i);
                        projectiles.erase(projectiles.begin() + k);
                        break;
                    }
                }
            }
        }




        // clear the window with black color
        window.clear(Color::Black);

        // draw everything here...
        window.draw(player);

        for (const auto& enemy : enemies)
            window.draw(enemy);
        for (const auto& projectile : projectiles)
            window.draw(projectile);

        // end the current frame
        window.display();
    }

    return 0;
}