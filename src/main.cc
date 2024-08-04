#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

int
main(int argc, char **argv)
{
  static bool kPress;
  sf::Event event;
  sf::Text text;
  sf::Font font;
  const char *fontPath = "font/fantasquesansmono-regular.otf";
  if (!font.loadFromFile(fontPath)){
    std::cout << "Error: When load font from file\n";
    return -1;
  }
  text.setFont(font);
  text.setString("Hello World!"); // set string
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Black);
  

  sf::RenderWindow window(sf::VideoMode(300, 600), "TodoApp");
 
  while (window.isOpen())
    {
      while (window.pollEvent(event))
        {
	  switch(event.type){
	    
	  case sf::Event::Closed:
	    window.close();
	    break;

	  case sf::Event::EventType::KeyPressed:
	    if(event.key.code == sf::Keyboard::Space){
	      std::cout << "INFO: space key press\n";
	    }
	    break;

	  case sf::Event::MouseButtonPressed:
	    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	      std::cout << "Você clicou com o botao direito\n";
	    break;
	    
	  }
        }

      window.clear(sf::Color::White);
      window.draw(text);
      window.display();
    }

  return 0;
} 
