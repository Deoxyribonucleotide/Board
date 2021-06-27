#include <SFML/Graphics.hpp>
#include<iostream>
#include"Line.h"
#include"Client.h"
using namespace std;

int main()
{
	
	sf::RenderWindow window(VideoMode(1000, 500), "Board");
	dl::Line line;
	dl::Line line2;
	Vector2i external;
	Client client;

	thread _rcv([&]() {while (1) client.Receive(line2); });

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				_rcv.detach();
			}	
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			line.AddPosition(Mouse::getPosition(window));
			client.FillPacket(Mouse::getPosition(window));
		}


		if (Keyboard::isKeyPressed(Keyboard::C))
			line.Clear();

		if (!Mouse::isButtonPressed(Mouse::Left) && line.GetSize() >= 1 && line.PositionAt(line.GetSize() - 1) != external)
		{
			line.AddPosition(external);
			client.FillPacket(external);
		}

		window.clear();
		line.Draw(window);
		line2.Draw(window);
		window.display();
	}
	return 0;
}