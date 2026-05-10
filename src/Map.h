#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

class Map
{
public:
    Map();

    void Initialize();
    void Load();
    void Draw(sf::RenderWindow &window);

private:
    const sf::Vector2f tileSize{16, 16};
    const sf::Vector2f worldSizeTiles{100, 100};

    sf::Texture worldTexture;
    sf::VertexArray backgroundVertices;
    std::vector<int> backgroundTexTiles;
    // midground tiles
    // foreground tiles
};
int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "RPG");
    // window.setFramerateLimit(60);
    sf::Texture texture;
    if (!texture.loadFromFile("Player/Assets/playerspritesheet.png"))
    {
        cout << "Failed\n";
        return -1;
    }
    sf::Sprite sprite(texture);
    cout << "loaded\n";
    sprite.setTextureRect(sf::IntRect({ 0, 3*145 }, {85, 145}));
    sprite.scale(sf::Vector2f(1, 1));

    sf::Clock timemeasure;
    while (window.isOpen())
    {
        float dt = timemeasure.restart().asSeconds();
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            sprite.setTextureRect(sf::IntRect({ 0, 3*145 }, {85, 145}));
            sprite.move({0.f,-200.f *dt});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            sprite.setTextureRect(sf::IntRect({ 0, 0*145 }, {85, 145}));
            sprite.move({0.f,200.f *dt});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            sprite.setTextureRect(sf::IntRect({ 0, 2*145 }, {85, 145}));
            sprite.move({200.f *dt,0.f});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            sprite.setTextureRect(sf::IntRect({ 0, 1*145 }, {85, 145}));
            sprite.move({-200.f *dt,0.f});
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}