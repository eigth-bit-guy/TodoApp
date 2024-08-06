#include <iostream>
#include <SFML/Graphics.hpp>
#include "text.hpp"

class TextFont
{
public:
  int set_text_and_font(sf::Text *text, sf::Font *font);
};

int TextFont::set_text_and_font(sf::Text *text, sf::Font *font)
{
  const char *fontPath = "font/fantasquesansmono-regular.otf";
  if (!font->loadFromFile(fontPath)){
    std::cout << "Error: When load font from file\n";
    return -1;
  }
  text->setFont(*font);
  text->setString("Hello World!"); // set string
  text->setCharacterSize(24);
  text->setFillColor(sf::Color::Black);

  return 0;
}
