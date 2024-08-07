#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "text.hpp"

int
main(int argc, char **argv)
{
  TextFont tf;
  Editor e;
  e.sb.count = 0;
  int err;
  sf::Event event;
  sf::Text text;
  sf::Font font;

  err = tf.set_font(&text, &font);
  if(err == -1){
    std::cout << "Error: set_text_and_font\n";
    return -1;
  }
  
  sf::RenderWindow window(sf::VideoMode(300, 600), "TodoApp");
  sf::Vector2u myVector(300, 600);
  window.setSize(myVector);
 
  while (window.isOpen()) {
    
    while (window.pollEvent(event)) {
      
      switch(event.type) {
	    
      case sf::Event::Closed:
	window.close();
	break;

      case sf::Event::TextEntered:
	if (event.text.unicode < 128){
	  std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
	  tf.input_text_to_buff(&e, static_cast<char>(event.text.unicode), &text);
	}
      }
    }
    window.setKeyRepeatEnabled(false);
    window.clear(sf::Color::White);
    window.draw(text);
    window.display();
  }

  return 0;

} 
