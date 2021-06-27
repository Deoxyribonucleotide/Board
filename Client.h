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
	vector<sf::UdpSocket> sockets;
	sf::UdpSocket socket;
	sf::IpAddress _localip;
	vector<unsigned short> ports;
	unsigned short port;
	vector<sf::Packet> packets;
	sf::Packet packet;
	vector<sf::Vector2i> pos;
	int i;
};

