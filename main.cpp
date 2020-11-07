#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1000, 600), "Board");
    CircleShape shape(8);
    shape.setFillColor(Color::Green);

    RenderTexture texture;
    texture.create(1000, 600);
    texture.clear(Color::White);
    

    Sprite spr(texture.getTexture());

    Vector2i pixelPos = Mouse::getPosition(window);
    Vector2f pos = window.mapPixelToCoords(pixelPos);

    int x = 0, y = 0;
    bool draw = true;

    while (window.isOpen())
    {
        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::B))
                shape.setFillColor(Color::Blue);

            if (Keyboard::isKeyPressed(Keyboard::Q))
                texture.clear(Color::White);
            
            if (event.type == Event::MouseButtonPressed)
               if (event.key.code == Mouse::Right)
                    draw = !draw;
                
            if (draw)
            {
                x = pos.x;
                y = pos.y;
                shape.setPosition(x, 600 -y);
                texture.draw(shape); 
            }  
        }
        window.clear();

        window.draw(spr);
        window.display();
    }

    return 0;
}