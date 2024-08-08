#include <iostream>
#include <SFML/Graphics.hpp>
#include "text.hpp"

int
TextFont::set_font(sf::Text *text, sf::Font *font)
{
  const char *fontPath = "font/fantasquesansmono-regular.otf"; //add macro for this
  if (!font->loadFromFile(fontPath)){
    std::cout << "Error: When load font from file\n";
    return -1;
  }

  text->setFont(*font);
  text->setCharacterSize(24);
  text->setFillColor(sf::Color::Black);
  return 0;
}

void
TextFont::input_text_to_buff(Editor *e , char ch, sf::Text *text)
{
  insert_buff(e, &ch, 1, text);
}

void
TextFont::insert_buff(Editor *e, char *x, size_t buff_len, sf::Text *text)
{
  for(size_t i = 0; i < buff_len; i++){
    e->sb->buff[e->sb->count] = *x;
  }
  e->sb->count += 1;

  text->setString(e->sb->buff);
}
