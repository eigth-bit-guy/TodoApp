#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

int
main(int argc, char **argv)
{
  // TextFont tf;
  // Editor e;
  // e.sb->count = 0;
  // int err;
  sf::Event event;
  sf::Text text;
  sf::Font font;
  sf::RenderWindow wd;
  sf::RenderWindow window;

  const char *fontPath = "font/fantasquesansmono-regular.otf"; //add macro for this
  if (!font.loadFromFile(fontPath)){
    std::cout << "Error: When load font from file\n";
    return -1;
  }
  
  // err = tf.set_font(&text, &font);
  // if(err == -1){
  //   std::cout << "Error: set_text_and_font\n";
  //   return -1;
  // }
  
  wd.create(sf::VideoMode(800, 600), "TodoApp");
  sf::Vector2u vec = wd.getSize();
  unsigned int wh = vec.x / 2;
  unsigned int hg = vec.y / 2;
  wd.setPosition(sf::Vector2i(wh, hg));
  wd.setVerticalSyncEnabled(true); // frame

  while (wd.isOpen()) {
    
    while (wd.pollEvent(event)) {
      
      switch(event.type) {
	    
      case sf::Event::Closed:
	std::cout << "INFO: close button pressed\n";
        wd.close();
	break;
      }
    }

    wd.clear(sf::Color::Red);
    wd.display();
  }

  return 0;

} 
