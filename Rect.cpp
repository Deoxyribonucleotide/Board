#include "Rect.h"
dl::Rect::Rect()
{
	int MouseX = 0;
	int MouseY = 0;
	color = Color::Black;
	rect.setFillColor(color);
	rect.setSize(Vector2f(2, 2));
	
}

RectangleShape dl::Rect::GetRectangle()
{
	return rect;
}

void dl::Rect::ChangeColor(RenderTexture* texture)
{

    if (Keyboard::isKeyPressed(Keyboard::G))
        rect.setFillColor(Color::Green);

    if (Keyboard::isKeyPressed(Keyboard::R))
        rect.setFillColor(Color::Red);

    if (Keyboard::isKeyPressed(Keyboard::B))
        rect.setFillColor(Color::Blue);

    if (Keyboard::isKeyPressed(Keyboard::Q))
        texture->clear(Color::White);

    this->color = rect.getFillColor();
    
}

void dl::Rect::GetMousePos(RenderWindow* window)
{
    Pos = window->mapPixelToCoords(Mouse::getPosition(*window));
    MouseX = Pos.x;
    MouseY = Pos.y;
}

void dl::Rect::SetRectanglePos()
{
    rect.setPosition(MouseX, 600 - MouseY);
}
