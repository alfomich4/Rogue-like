// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Application.h"


using namespace RogueLikeGame;
const std::string RESOURCES_PATH = "Resources/";

int main()
{
    const unsigned int WIDTH = 800;
    const unsigned int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "RogueLikeGame");

   
    sf::Font font;
    if (!font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"))
        return EXIT_FAILURE;

    // 2. Создаём текст
    sf::Text message;
    message.setFont(font);
    message.setString("TO BE DONE\nPress Esc to exit to menu");
    message.setCharacterSize(24);
    message.setFillColor(sf::Color::White);

    // Центруем текст
    sf::FloatRect bounds = message.getLocalBounds();
    message.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    message.setPosition(WIDTH / 2.f, HEIGHT / 2.f);

    // Главный цикл
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Закрыть окно по крестику или по Esc
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(message);
        window.display();
    }
	/*Application::Instance().Run();*/

	return 0;
}
