#include <Siv3D.hpp>
#include "game.hpp"
#include <iostream>

void Main()
{
  Scene::SetBackground(ColorF(0.8, 0.9, 1.0));
  Window::Resize(1366, 768);

  p30kG::Game game;

  game.setFieldData();

  while (System::Update()) {
    game.dispField();
  }
}
