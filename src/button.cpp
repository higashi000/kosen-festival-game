#include "button.hpp"

p30kG::Button::Button() {
  rect = Rect(100, 100, 70, 70);
  nowColor = 0;
  isArea = 0;
  point = U"";
  font = Font(30);
  pos = Vec2(0, 0);
}

p30kG::Button::Button(int color, int area, int x, int y, String tilePoint) {
  rect = Rect(x, y, 70, 70);
  nowColor = color;
  isArea = area;
  point = tilePoint;
  font = Font(30);
  pos = Vec2(x, y);
  rect.setPos(x, y);
}

p30kG::Button &p30kG::Button::draw() {
  if (nowColor == 0) {
    if (isArea == 0) {
      rect.draw(Color(255, 255, 255));
    } else if (isArea == 1) {
      rect.draw(Color(234, 145, 152));
    } else if (isArea == 2) {
      rect.draw(Color(184, 192, 0));
    }
  } else if (nowColor == 1) {
    rect.draw(Color(255, 0, 0));
  } else if (nowColor == 2) {
    rect.draw(Color(0, 0, 255));
  }

  font(point).draw(pos, Palette::Black);

  return *this;
}
