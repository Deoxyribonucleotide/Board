#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include"Rect.h"
#include<iostream>
#include<vector>
#include<thread>
#include<string>
#pragma once

using namespace sf;
using namespace std;

class Client
{
public:

	Client();

	void GetMousePos(RenderWindow* window);

	bool GetDraw();

	void ChangeDraw();

	RectangleShape GetRectangle(int index);
	
	void SetRectanglePos(int index);

	void SendCoordinates();

	void ReceiveCoordinates();

	void FillPacket();

	void ChangeColor(RenderTexture* texture);

	void Draw(RenderTexture* texture);

private:

	bool draw = true;

	vector<dl::Rect> rectangles{};
	dl::Rect rect;

	IpAddress IP;
	TcpSocket socket;
	int port;
	unsigned short serverport = 2000;

	Packet packet;
	Packet packet2;
	//string str;
};

