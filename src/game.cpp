#include "game.hpp"

namespace p30kG {
Game::Game() {
  field = conn.getFieldData();
  font = Font(70);
  buttons = Array<Array<p30kG::Button>>(field.height, Array<p30kG::Button>(field.width));
}
void Game::dispField() {
  for (int y : step(field.height)) {
    for (int x : step(field.width)) {
      buttons[y][x].draw();
    }
  }

  for (int z : step(field.agentNum)) {
    buttons[field.myAgentData[z][2]][field.myAgentData[z][1]].draw(true);
  }

  font(U"自分の得点:").draw(Vec2(800, 50), Color(0, 0, 255));
  font(field.myAreaPoint + field.myTilePoint).draw(Vec2(1200, 50), Color(0, 0, 255));
  font(U"相手の得点:").draw(Vec2(800, 130), Color(255, 0, 0));
  font(field.rivalAreaPoint + field.rivalTilePoint).draw(Vec2(1200, 130), Color(255, 0, 0));

  font(U"ターン:").draw(Vec2(800, 410), Color(0, 0, 0));
  font(field.turn).draw(Vec2(1050, 410), Color(0, 0, 0));
  font(U"/").draw(Vec2(1100, 410), Color(0, 0, 0));
  font(field.maxTurn).draw(Vec2(1150, 410), Color(0, 0, 0));
}

void Game::setFieldData() {
  for (int i = 0; i < field.height; ++i) {
    for (int j = 0; j < field.width; ++j) {
      buttons[i][j] = p30kG::Button(field.color[i][j], field.areaPointInfo[i][j], i * 75, j * 75, field.point[i][j]);
    }
  }
}
}
