#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#ifdef DEBUG
#include <iostream>
#endif

namespace td {
  class TodoApp {

  public:
    int width = 0;
    int height = 0;

    TodoApp(int main_window_width, int main_window_height){
      width = main_window_width;
      height = main_window_height;
    }

    int CreateButton(tgui::BackendGui& gui, tgui::Theme theme)
    {
      auto button = tgui::Button::create();
#ifdef DEBUG
      if(button == NULL){
	std::cout << "[DEBUG INFO ERROR] when create button" << '\n';
	return -1;
      }
#endif
      button->setRenderer(theme.getRenderer("Button"));
      button->setPosition(gui.getView().getSize().x - (width - 10),
			  gui.getView().getSize().y - (height - 10));
      button->setText("Add new task");
      button->setSize(100, 40);
      gui.add(button);
      return 0;
    }

    int CreateEditBox(tgui::BackendGui& gui, tgui::Theme theme)
    {
      auto editBox = tgui::EditBox::create();
#ifdef DEBUG
      if(editBox == NULL) {
	std::cout << "[DEBUG INFO ERROR] when create editBox" << '\n';
      }
#endif
      editBox->setRenderer(theme.getRenderer("EditBox"));
      editBox->setSize(200, 25);
      editBox->setTextSize(18);
      editBox->setPosition(10, 80);
      editBox->setDefaultText("Title");
      gui.add(editBox);
      return 0;
    }
  };
};
