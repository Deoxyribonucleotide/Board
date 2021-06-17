#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#pragma once
using namespace sf;
using namespace std;

namespace dl
{
	class Line
	{
	public:
		Line();

		void SetColor(Color color);

		void SetPosition(vector<Vector2i> position);

		VertexArray GetLine();

		Vector2i PositionAt(int number);

		int GetSize();

		void AddPosition(Vector2i points);

		void Clear();

		void Draw(sf::RenderWindow& window);

	private:
		VertexArray line;
		int length;
		vector<Vector2i> position;
		vector<Vector2i> readypoints;
		Vector2i external;
	};
}