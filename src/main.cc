#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "text.hpp"

int
main(int argc, char **argv)
{
  TextFont tf;
  int err;
  sf::Event event;
  sf::Text text;
  sf::Font font;

  err = tf.set_text_and_font(&text, &font);
  if(err == -1){
    std::cout << "Error: set_text_and_font\n";
    return -1;
  }
  
  sf::RenderWindow window(sf::VideoMode(300, 600), "TodoApp");
 
  while (window.isOpen()) {
    
    while (window.pollEvent(event)) {
	
      switch(event.type) {
	    
      case sf::Event::Closed:
	window.close();
	break;

      case sf::Event::EventType::KeyPressed:
	if(event.key.code == sf::Keyboard::Space){
	  std::cout << "INFO: space key press\n";
	}else if(event.key.code == sf::Keyboard::Escape){
	  std::cout << "INFO: escape key press\n";
	}
	break;

      case sf::Event::MouseButtonPressed:
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	  std::cout << "INFO: você clicou com o botao direito\n";
	break;
	    
      }
    }

      window.clear(sf::Color::White);
      window.draw(text);
      window.display();
    }

  return 0;

} 
