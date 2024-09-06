#include <iostream>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

int main(int argc, char **argv)
{
  sf::RenderWindow window{{300, 600}, "TGUI example - SFML_GRAPHICS backend"};
  tgui::Gui gui{window};

  tgui::Button::Ptr button = tgui::Button::create();
  auto editBox = tgui::EditBox::create();
  gui.add(button);
  gui.add(editBox, "MyWidgetName");

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  gui.handleEvent(event);

	  if (event.type == sf::Event::Closed)
            window.close();
	}

      window.clear();
      gui.draw();
      window.display();
    }  
}
