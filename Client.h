#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<vector>
#include"Line.h"
#include<thread>
#include<string>
#pragma once

using namespace std;

class Client
{
public:

	Client();

	sf::IpAddress GetMyIp();

	void Send(sf::Packet packet);

	void FillPacket(sf::Vector2i position);

	void Receive(dl::Line& line);

private:
	sf::UdpSocket socket;
	sf::UdpSocket socket2;
	sf::IpAddress _localip;
	unsigned short port = 54001;
	unsigned short port2 = 54000;
	sf::Packet packet;
	sf::Packet packet2;
	vector<sf::Vector2i> pos;
	int i;
};

