#include <SFML/Graphics.hpp>
#include<SFML/Network.hpp>
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

	Client(RenderTexture* texture, RenderWindow* window);

	void GetMousePos();

	bool GetDraw();

	void ChangeDraw();

	RectangleShape GetRectangle(int index);
	
	void SetRectanglePos(int index);

	void SendCoordinates();

	void ReceiveCoordinates();

	void FillPacket();

	void ChangeColor();

	void Draw();

private:

	int mouseX = 0;
	int mouseY = 0;
	bool draw = true;

	Vector2i pixelPos;
	Vector2f Pos;
	Vector2f Pos2;

	vector<RectangleShape> rectangles{};
	RectangleShape rect;

	RenderTexture *texture;
	RenderWindow *window;

	IpAddress IP;
	TcpSocket socket;
	int port;
	unsigned short serverport = 2000;

	Packet packet;
	Packet packet2;
	//string str;

	Color color;
};

