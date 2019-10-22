#include <Siv3D.hpp>
#include "game.hpp"
#include <iostream>

void Main()
{
  Scene::SetBackground(ColorF(0.8, 0.9, 1.0));
  Window::Resize(1366, 768);

  p30kG::Game game;

  game.setFieldData();
  Rect rect = Rect(683, 384, 500, 500);
  bool start = false;

  while (System::Update()) {
    if (!start) rect.draw(Palette::Magenta);
    if (rect.leftClicked()) {
      start = true;
      game.turnSt = time(NULL);
    }
    if (start) game.dispField();
  }
}
