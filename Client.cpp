#include "Client.h"

Client::Client()
{
    for (int i = 0; i < 10; i++)
    {
        rectangles.push_back(rect);
    }
    IP = IpAddress::getLocalAddress();
    cout << IP << endl;
    port = 3000;
    socket.setBlocking(false);
    cout << socket.getLocalPort() << endl;
    socket.connect(IP, port);

}

void Client::GetMousePos(RenderWindow* window)
{
    rectangles[0].GetMousePos(window);
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
    return rectangles[index].GetRectangle();
}

void Client::SetRectanglePos(int index)
{
    rectangles[index].SetRectanglePos();
}

void Client::SendCoordinates()
{
    socket.send(packet);
    packet.clear();
}
//fill packet
/*void Client::FillPacket()
{
    packet << mouseX << mouseY;
}*/

void Client::ChangeColor(RenderTexture* texture)
{
    cout << "thread color" << endl;
    while (1)
        rectangles[0].ChangeColor(texture);
}

void Client::Draw(RenderTexture* texture)
{
    cout << "thread draw" << endl;
    while (true)
    {
        rectangles[0].SetRectanglePos();
        texture->draw(rectangles[0].GetRectangle());
    } 
}

/*void Client::ReceiveCoordinates()
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
}*/