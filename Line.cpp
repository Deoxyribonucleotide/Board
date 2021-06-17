#include "Line.h"

dl::Line::Line()
{
	line.setPrimitiveType(LinesStrip);
	line.resize(2);
	length = 2;
}

void dl::Line::SetColor(Color color)
{
	for (int i = 0; i < length; i++)
		line[i].color = color;
}

void dl::Line::SetPosition(vector<Vector2i> position)
{
	line[0].position = Vector2f(position[0].x, position[0].y);
	line[1].position = Vector2f(position[1].x, position[1].y);
}

VertexArray dl::Line::GetLine()
{
	return line;
}

Vector2i dl::Line::PositionAt(int number)
{
	return position[number];
}

int dl::Line::GetSize()
{
	return position.size();
}

void dl::Line::AddPosition(Vector2i points)
{
	position.push_back(points);
}

void dl::Line::Clear()
{
	position.clear();
}

void dl::Line::Draw(sf::RenderWindow& window)
{
	readypoints.clear();
	if (position.size() >= 2)
	{
		for (int i = 0; i < position.size(); i++)
		{
			if (readypoints.size() == 2)
			{
				if (dl::Line::PositionAt(i) == external)
					readypoints.clear();
				else
				{
					dl::Line::SetPosition(readypoints);
					window.draw(dl::Line::GetLine());
					readypoints.erase(readypoints.begin(), readypoints.begin() + 1);
				}
			}
			if (dl::Line::PositionAt(i) != external)
				readypoints.push_back(dl::Line::PositionAt(i));
		}
	}
}
