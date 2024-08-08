#ifndef __TEXT__
#define __TEXT__

typedef struct{
  char buff[100];
  int count;
}StringBuffer;

typedef struct{
  StringBuffer *sb;
  int cursor;
}Editor;

class TextFont{
public:
  int set_font(sf::Text *text, sf::Font *font);
  void input_text_to_buff(Editor *e, char ch, sf::Text *text);

protected:
  void insert_buff(Editor *e, char *x, size_t buff_len, sf::Text *text);
};

#endif
