#include "Client.h"

Client::Client()
{
    _localip = sf::IpAddress::getLocalAddress();
    
    cin >> i;
    if (i == 2)
    {
        cin >> port2;
        if (socket.bind(port2) != sf::Socket::Done)
            cout << "can not bind a socket" << endl;
        socket.setBlocking(false);
    }
       
    else
    {
        cin >> port;
        if (socket2.bind(port) != sf::Socket::Done)
            cout << "can not bind a socket" << endl;
        socket2.setBlocking(false);
    }

    cout << _localip << endl;

    pos.push_back(Vector2i(0, 0));
}

sf::IpAddress Client::GetMyIp()
{
    return _localip;
}

void Client::Send(sf::Packet packet)
{
    if(i==2)
        socket2.send(packet, _localip, port);
    else
        socket.send(packet, _localip, port2);

    packet.clear();
}

void Client::FillPacket(sf::Vector2i position)
{
    packet << position.x << position.y;

    Client::Send(packet);
}

void Client::Receive(dl::Line& line)
{
    if (i == 2)
    {
        socket.receive(packet2, _localip, port2);
            if (packet2 >> pos[0].x >> pos[0].y)
                line.SetPosition(pos);
    }
    else
    {
        socket2.receive(packet2, _localip, port);
        if (packet2 >> pos[0].x >> pos[0].y)
            line.SetPosition(pos);
    }
    //cout << packet2.getDataSize();
    packet2.clear();
    
}

