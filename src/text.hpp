#ifndef __TEXT__
#define __TEXT__

class TextFont{
public:
  typedef struct{
    char buff[100]; // for tests
    int count;
  }StringBuffer;

  typedef struct{
    StringBuffer *sb;
    int cursor;
  }Editor;
  
  int set_font(sf::Text *text, sf::Font *font);
  void input_text_to_buff(Editor *e, char ch, sf::Text *text);

protected:
  void insert_buff(Editor *e, char x, size_t buff_len, sf::Text *text);
};

#endif
