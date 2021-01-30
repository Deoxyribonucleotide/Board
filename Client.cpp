#include "Client.h"

Client::Client(RenderTexture* texture, RenderWindow* window)
{
    rect.setSize(Vector2f(2, 2));
    rect.setFillColor(Color::Red);
    for (int i = 0; i < 10; i++)
    {
        rectangles.push_back(rect);
    }
    color = Color::Black;
    rectangles[0].setFillColor(color);

    IP = IpAddress::getLocalAddress();
    cout << IP << endl;
    port = 3000;
    socket.setBlocking(false);
    cout << socket.getLocalPort() << endl;
    socket.connect(IP, port);

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
    socket.send(packet);
    cout << packet.getDataSize() << " ";
    packet.clear();
}

void Client::FillPacket()
{
    packet << mouseX << mouseY;
}

void Client::ChangeColor()
{
    cout << "thread color" << endl;
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
    cout << "thread draw" << endl;
    while (true)
    {
        rectangles[0].setPosition(mouseX, 600 - mouseY);
        texture->draw(rectangles[0]);
    } 
}

void Client::ReceiveCoordinates()
{
    while (true)
    {
        socket.receive(packet2);
        if (packet2 >> Pos2.x >> Pos2.y)
        {
            rectangles[1].setPosition(Pos2.x, 600 - Pos2.y);
            packet2.clear();
            texture->draw(rectangles[1]);
        }
    }
}