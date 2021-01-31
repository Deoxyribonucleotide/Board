#include <SFML/Graphics.hpp>
#include<iostream>
#pragma once
using namespace sf;
namespace dl
{
	class Rect
	{
	public:
		Rect();

		RectangleShape GetRectangle();

		void ChangeColor(RenderTexture* texture);

		void GetMousePos(RenderWindow* window);

		void SetRectanglePos();
	private:
		RectangleShape rect;
		int MouseX;
		int MouseY;
		Color color;
		Vector2f Pos;
	};

}
