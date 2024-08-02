#include <iostream>
#include <SFML/Graphics.hpp>

int
main(int argc, char **argv)
{
  sf::Text text;
  sf::Font font;
  const char *fontPath = "font/fantasquesansmono-regular.otf";
  if (!font.loadFromFile(fontPath)){
    std::cout << "Error: When load font from file\n";
    return -1;
  }
  text.setFont(font);
  text.setString("Hello World");
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Red);
  

  sf::RenderWindow window(sf::VideoMode(300, 600), "SFML works!");
 
  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
	  if (event.type == sf::Event::Closed)
	    window.close();
        }

      window.clear();
      window.draw(text);
      window.display();
    }

  return 0;
} 
