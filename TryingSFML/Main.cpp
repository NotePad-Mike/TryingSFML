#include <SFML\Graphics.hpp>

void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color);

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 180), "Animation");
	//Set target FPS
	window.setFramerateLimit(60);

	sf::Vector2f startPos = sf::Vector2f(50, 50);
	sf::RectangleShape playerRect(sf::Vector2f(50, 50));
	initShape(playerRect, startPos, sf::Color::Green);
	sf::RectangleShape targetRect(sf::Vector2f(50, 50));
	initShape(targetRect, sf::Vector2f(400, 50), sf::Color::Blue);
	sf::RectangleShape badRect(sf::Vector2f(50, 100));
	initShape(badRect, sf::Vector2f(250, 50), sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Update frame
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			playerRect.move(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			playerRect.move(-1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			playerRect.move(0 ,1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			playerRect.move(0, -1);

		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
			window.close();
		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
			playerRect.setPosition(startPos);

		//Render the object
		window.clear();
		window.draw(playerRect);
		window.draw(targetRect);
		window.draw(badRect);
		window.display();
	}
	return 0;
}

void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color)
{
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);
}