#include <Siv3D.hpp>
#include "game.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

void Main()
{
  Scene::SetBackground(ColorF(0.8, 0.9, 1.0));
  Window::Resize(1366, 768);

  p30kG::Game game;

  Rect rect = Rect(433, 259, 500, 250);
  Rect restart = Rect(500, 200, 433, 500);
  Font font = Font(100);
  Font result = Font(100);
  bool start = false;
  bool finishGame = false;

  while (System::Update()) {
    if (!start && !finishGame) {
      rect.draw(Palette::Magenta);
      font(U"スタート").draw(Vec2(483, 334), Palette::Black);

      if (rect.leftClicked()) {
        system("bash ./start.sh");
        start = true;
        game = p30kG::Game(true);
        game.turnSt = time(NULL);
        game.setFieldData();
      }
    }

    if (start) {
      if (!game.dispField()) {
        start = false;
        finishGame = true;
      }
    }

    if (finishGame) {
      game.finishGame();
      restart.draw(Palette::Magenta);
      if (restart.leftClicked()) {
        finishGame = false;
        game.conn.reloadField();
        game.turn = 1;
      }
    }
  }
}
