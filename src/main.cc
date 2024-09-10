#include <iostream>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#define WIDTH 500
#define HEIGHT 700
#define WIDTH_BUTTON (WIDTH - 10)
#define HEIGHT_BUTTON (HEIGHT - 10)

void add_editbox(tgui::BackendGui& gui, tgui::Theme theme)
{
  auto editBox = tgui::EditBox::create();
  editBox->setRenderer(theme.getRenderer("EditBox"));
  editBox->setSize(200, 25);
  editBox->setTextSize(18);
  editBox->setPosition(10, 80);
  editBox->setDefaultText("Title");
  gui.add(editBox);
}

int main(int argc, char **argv)
{
  sf::Mouse mouse;
  sf::RenderWindow window{{WIDTH, HEIGHT}, "TodoApp"};
  tgui::Gui gui{window};
  tgui::Theme theme{"themes/Black.txt"};

  auto button = tgui::Button::create();
  button->setRenderer(theme.getRenderer("Button"));
  button->setPosition(gui.getView().getSize().x - WIDTH_BUTTON,
		      gui.getView().getSize().y - HEIGHT_BUTTON);
  button->setText("Add new task");
  button->setSize(100, 40);
  gui.add(button);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      gui.handleEvent(event);
	  
      if (event.type == sf::Event::Closed)
	window.close();
	  
      if(event.type == mouse.isButtonPressed(sf::Mouse::Button::Left)){
	add_editbox(gui, theme);
      }
    }
    window.clear(sf::Color::Red);
    gui.draw();
    window.display();
  }
}
