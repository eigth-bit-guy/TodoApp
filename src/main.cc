#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

int
main(int argc, char **argv)
{
  sf::Event event;
  sf::Text text;
  sf::Font font;
  sf::RenderWindow window;
  sf::Texture texture;

  const char *fontPath = "font/fantasquesansmono-regular.otf"; //add macro for this
  const char *texturePath = "font/bitmap_font/bitmap_font.png";

  if (!font.loadFromFile(fontPath)){
    std::cout << "Error: When load font from file\n";
    return -1;
  }
  if(!texture.loadFromFile(texturePath)){
    std::cout << "INFO: error when load texture from file\n";
    return -1;
  }
  
  window.create(sf::VideoMode(800, 600), "TodoApp");
  sf::Vector2u vec = window.getSize();
  unsigned int wh = vec.x / 2;
  unsigned int hg = vec.y / 2;
  window.setPosition(sf::Vector2i(wh, hg));
  window.setVerticalSyncEnabled(true); // frame

  while (window.isOpen()) {
    
    while (window.pollEvent(event)) {
      
      switch(event.type) {
	    
      case sf::Event::Closed:
	std::cout << "INFO: close button pressed\n";
        window.close();
	break;
      }
    }

    window.clear(sf::Color::Red);
    window.display();
  }

  return 0;

} 
