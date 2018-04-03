#include <SFML\Graphics.hpp>

void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos);

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 180), "Animation");
	//Set target FPS
	window.setFramerateLimit(60);

	//Create images then textures for the shapes
	sf::Image player, target, enemy;
	player.create(50, 50, sf::Color::Green);
	target.create(50, 50, sf::Color::Blue);
	enemy.create(50, 100, sf::Color::Red);

	sf::Texture playerT, targetT, enemyT;
	playerT.loadFromImage(player);
	targetT.loadFromImage(target);
	enemyT.loadFromImage(enemy);
	

	sf::Vector2f startPos = sf::Vector2f(50, 50);
	sf::RectangleShape playerRect(sf::Vector2f(50, 50));
	playerRect.setTexture(&playerT);
	initShape(playerRect, startPos);
	sf::RectangleShape targetRect(sf::Vector2f(50, 50));
	targetRect.setTexture(&targetT);
	initShape(targetRect, sf::Vector2f(400, 50));
	sf::RectangleShape badRect(sf::Vector2f(50, 100));
	badRect.setTexture(&enemyT);
	initShape(badRect, sf::Vector2f(250, 90));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Update frame
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			playerRect.move(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			playerRect.move(-1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			playerRect.move(0 ,1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			playerRect.move(0, -1);

		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
			window.close();
		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
			playerRect.setPosition(startPos);

		badRect.rotate(1.5f);

		//Render the object
		window.clear();
		window.draw(playerRect);
		window.draw(targetRect);
		window.draw(badRect);
		window.display();
	}
	return 0;
}

void initShape(sf::RectangleShape& shape, sf::Vector2f const& pos)
{
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f);
}