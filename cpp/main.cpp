#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

// int randomIndex = rand() % MAX; -> returns a value between 0 and MAX (not inclusive) 

// NOTE: Continue reading from "1.4: A normal distribution  of random numbers"


int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 960), "SFML works!");

    srand(time(NULL));

	sf::RectangleShape walker(sf::Vector2f(1, 1));
	walker.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	walker.setFillColor(sf::Color::White);

    while (window.isOpen())
	{
        sf::Event event;
        while (window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}
        }

        // window.clear(sf::Color::White);

		float deltaX = 0.0f;
		float deltaY = 0.0f;

		float probability = (float)(rand() % 101) / 100.0f;


		if (probability < 0.3)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window); 
			sf::Vector2i walkerPos((int)walker.getPosition().x, (int)walker.getPosition().y);
			int mouseRelPosX = mousePos.x - walkerPos.x;
			int mouseRelPosY = walkerPos.y - mousePos.y;

			deltaX = (mouseRelPosX > 0) ? 1 : -1;
			deltaY = (mouseRelPosY > 0) ? -1 : 1; // negative Y means "up"
		}
		else if (probability > 0.5 && probability < 0.6)
		{
			deltaX = -1;
		}
		else if (probability > 0.7 && probability < 0.8)
		{
			deltaY = 1;
		}
		else if (probability > 0.8 && probability < 0.9)
		{
			deltaY = -1;
		}
		else if (probability > 0.9 && probability < 1.0)
		{
			deltaX = 1;
		}

		walker.move(deltaX, deltaY);

        window.draw(walker);
        window.display();

    }

    return 0;
}