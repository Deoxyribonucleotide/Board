#include "Client.h"

Client::Client()
{
    _localip = sf::IpAddress::getLocalAddress();
    ports.push_back(port);
    ports.push_back(port);
    ports[0] = 54000;
    ports[1] = 54001;
    sockets.push_back(socket);
    sockets.push_back(socket);

    sockets[0].setBlocking(false);
    sockets[0].bind(ports[0]);

    sockets[1].setBlocking(false);
    sockets[1].bind(ports[1]);

    packets.push_back(packet);
    packets.push_back(packet);

    cout << _localip << endl;

    pos.push_back(Vector2i(0, 0));

    cin >> i;
}

sf::IpAddress Client::GetMyIp()
{
    return _localip;
}

void Client::Send(sf::Packet packet)
{
    if(i==2)
        sockets[0].send(packet, _localip, ports[1]);
    else
        sockets[1].send(packet, _localip, ports[0]);

    packet.clear();
}

void Client::FillPacket(sf::Vector2i position)
{
    packets[0] << position.x << position.y;

    Client::Send(packets[0]);
}

void Client::Receive(dl::Line& line)
{
    if (i == 2)
    {
        socket.receive(packets[1], _localip, port);
            if (packets[1] >> pos[0].x >> pos[0].y)
                line.SetPosition(pos);
    }
    else
    {
        sockets[1].receive(packets[1], _localip, port);
        if (packets[1] >> pos[0].x >> pos[0].y)
            line.SetPosition(pos);
    }
    //cout << packet2.getDataSize();
    packets[1].clear();
    
}

