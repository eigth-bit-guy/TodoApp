#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "Widget.hpp"
#define WIDTH 500
#define HEIGHT 700

#ifdef DEBUG
#include <iostream>
#endif
#define DEBUG

int main(int argc, char **argv)
{
  sf::RenderWindow window{{WIDTH, HEIGHT}, "TodoApp"};
  tgui::Gui gui{window};
  tgui::Theme theme{"themes/Black.txt"};
  td::TodoApp todo(WIDTH, HEIGHT);
  todo.CreateButton(gui, theme);
  
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      gui.handleEvent(event);
	  
      if (event.type == sf::Event::Closed)
	window.close();
	  
    }
    window.clear(sf::Color::Red);
    gui.draw();
    window.display();
  }
}
