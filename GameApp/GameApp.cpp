
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

int main()
{

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");
	sf::CircleShape shape(30.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(100, 100);

	cout << "Another example of how to invoke the console";

	sf::VertexArray piece(sf::LinesStrip, 5);

	piece[0].position = sf::Vector2f(30, 20);
	piece[0].color = sf::Color::Blue;

	piece[1].position = sf::Vector2f(60, 15);
	piece[1].color = sf::Color::Red;

	piece[2].position = sf::Vector2f(60, 45);
	piece[2].color = sf::Color::Green;

	piece[3].position = sf::Vector2f(30, 40);
	piece[3].color = sf::Color::Yellow;

	piece[4].position = sf::Vector2f(30, 20);
	piece[4].color = sf::Color::Blue;




	while (window.isOpen())
	{
		sf::Event thing;
		while (window.pollEvent(thing))
		{
			if (thing.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		window.clear();
		window.draw(shape);
		window.draw(piece);
		window.display();
	}

	return 0;

}
