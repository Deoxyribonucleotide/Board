#include "Client.h"

Client::Client(RenderTexture* texture, RenderWindow* window)
{
    
    for (int i = 0; i < 10; i++)
    {
        rectangles.push_back(rect);
    }
    rectangles[0].setSize(Vector2f(2, 2));
    color = Color::Black;
    rectangles[0].setFillColor(color);

    IP = IpAddress::getLocalAddress();
    cout << IP << endl;
    port = Socket::AnyPort;
    socket.bind(port);
    socket.setBlocking(false);
    cout << socket.getLocalPort() << endl;;

    Pos2.x = 0;
    Pos2.y = 0;
    
    this->texture = texture;
    this->window = window;
}

void Client::GetMousePos()
{
    pixelPos = Mouse::getPosition(*window);
    Pos = window->mapPixelToCoords(pixelPos);
    mouseX = Pos.x;
    mouseY = Pos.y;
}

bool Client::GetDraw()
{
    return draw;
}

void Client::ChangeDraw()
{
    draw = !draw;
}

RectangleShape Client::GetRectangle(int index)
{
    return rectangles[index];
}

void Client::SetRectanglePos(int index)
{
    rectangles[index].setPosition(mouseX, 600 - mouseY);
}

void Client::SendCoordinates()
{
    socket.send(packet,IP,2000);
    cout << packet.getDataSize() << " ";
    packet.clear();
}

void Client::FillPacket()
{
    packet << mouseX << mouseY;
    //color
}

void Client::ChangeColor()
{
    while (true)
    {
        if (Keyboard::isKeyPressed(Keyboard::G))
            rectangles[0].setFillColor(Color::Green);

        if (Keyboard::isKeyPressed(Keyboard::R))
            rectangles[0].setFillColor(Color::Red);

        if (Keyboard::isKeyPressed(Keyboard::B))
            rectangles[0].setFillColor(Color::Blue);

        if (Keyboard::isKeyPressed(Keyboard::Q))
            texture->clear(Color::White);
    
        this->color = rectangles[0].getFillColor();
    }
}

void Client::Draw()
{
    while (true)
    {
        rectangles[0].setPosition(mouseX, 600 - mouseY);
        texture->draw(rectangles[0]);
    } 
}

/*bool Client::ReceiveCoordinates() //mb in other thread
{
    socket.receive(packet2, IP, serverport);
    if (packet2 >> Pos2.x >> Pos2.y)
    {
        shape2.setPosition(Pos2.x, 600 - Pos2.y);
        packet2.clear();
        return 1;
    }
    
    return 0;
}*/