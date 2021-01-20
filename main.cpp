#include"Client.h"

int main()
{
    RenderWindow window(VideoMode(800, 600), "Board");

    RenderTexture texture;
    texture.create(800, 600);
    texture.clear(Color::White);

    Client client(&texture, &window);
   
    Sprite spr(texture.getTexture());
    int index = 0;

    thread th([] {&Client::Draw; });
    thread thColors([] {&Client::ChangeColor; });
    
    while (window.isOpen())
    {
        client.GetMousePos();
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                thColors.join();
                th.join();
                window.close();
            }

            /*if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Left)
                {
                    client.SetRectanglePos(index);
                    texture.draw(client.GetRectangle(index));
                }*/
            if (client.GetDraw())
            {
                client.FillPacket();
                client.SendCoordinates();
            } 
        }
        window.clear();
        window.draw(spr);
        window.display();
    }
    return 0;
}