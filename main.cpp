//#include"Client.h"
//
//int main()
//{
//    RenderWindow window(VideoMode(800, 600), "Board");
//
//    RenderTexture texture;
//    texture.create(800, 600);
//    texture.clear(Color::White);
//    texture.draw(button.GetButton());
//    Client client;
//
//    Sprite spr(texture.getTexture());
//    int index = 0;
//
//    //thread th([&]() {client.Draw(&texture); });
//    //thread thColors([&]() {client.ChangeColor(&texture); });
//    //thread thReceiving([&client]() {client.ReceiveCoordinates(); });
//    
//    while (window.isOpen())
//    {
//        client.GetMousePos(&window);
//        Event event;
//
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//            {
//                //thColors.detach();
//               // th.detach();
//                //thReceiving.detach();
//                window.close();
//            }
//            if (Mouse::isButtonPressed(Mouse::Button::Left))
//            if (button.IsPressed(&window, sf::Mouse::Button::Left))
//                cout << 1 << endl;
//           //client.StartMenu(&texture, &window);
//            //if (client.GetDraw())
//            //{
//            //    //client.FillPacket();
//            //    client.SendCoordinates();
//            //} 
//        }
//        window.clear();
//        window.draw(spr);
//        window.display();
//    }
//    return 0;
//}
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Line.h"
#include"Client.h"
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Board");
	dl::Line line;
	dl::Line line2;
	Vector2i external;
	//Client client;

	//thread thRcv([&client]() {while (1) client.Receive(); });

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			line.AddPosition(Mouse::getPosition(window));
			//client.FillPacket(Mouse::getPosition(window));
		}
			

		if (Keyboard::isKeyPressed(Keyboard::C))
			line.Clear();

		if (!Mouse::isButtonPressed(Mouse::Left) && line.GetSize() >= 1 && line.PositionAt(line.GetSize() - 1) != external)
		{
			line.AddPosition(external);
			//client.FillPacket(external);
		}
		//client.Receive(line2);

		window.clear();
		line.Draw(window);
		//line2.Draw(window);
		window.display();
	}
	return 0;
}