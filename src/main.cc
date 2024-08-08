#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

int
main(int argc, char **argv)
{
  sf::String stringBuffer;
  sf::Event event;
  sf::Text text;
  sf::Font font;
  sf::RenderWindow window;
  sf::Texture texture;
  size_t interartorString = 0;

  const char *fontPath = "font/fantasquesansmono-regular.otf"; //TODO: add macro for this
  const char *texturePath = "font/bitmap_font/bitmap_font.png";

  if (!font.loadFromFile(fontPath)){
    std::cout << "ERROR: When load font from file\n";
    return -1;
  }
  if(!texture.loadFromFile(texturePath)){
    std::cout << "ERROR: error when load texture from file\n";
    return -1;
  }

  text.setFont(font);
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Black);
  
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

      case sf::Event::TextEntered:
	std::cout << "INFO: entrada de texto: " << event.text.unicode << "\n";
	if(event.text.unicode == 8){ //backspace
	  stringBuffer.erase(interartorString - 1, 1);
	  if(interartorString != 0){
	    interartorString = interartorString - 1;
	  }else
	    break;
	}else if(event.text.unicode == 13){ //enter
	  stringBuffer.insert(interartorString, '\n');
	  interartorString += 1;
	}else{
	  stringBuffer.insert(interartorString, (char)event.text.unicode);
	  interartorString += 1;
	}
	text.setString(stringBuffer);
	// std::cout << "interator size: " << interartorString << "\n";
	// std::cout << "string buffer value: " << (std::string)stringBuffer << "\n";
	break;
      }
    }

    window.clear(sf::Color::White);
    window.draw(text);
    window.display();
  }

  return 0;
} 
