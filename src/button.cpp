#include "button.hpp"
#include <iostream>

p30kG::Button::Button() {
  rect = Rect(0, 0, 70, 70);
  nowColor = U"0";
  isArea = U"0";
  point = U"0";
  font = Font(30);
  pos = Vec2(0, 0);
}

p30kG::Button::Button(String color, String area, int x, int y, String tilePoint) {
  rect = Rect(x, y, 70, 70);
  nowColor = color;
  isArea = area;
  point = tilePoint;
  font = Font(30);
  pos = Vec2(x, y);
  posX = x + 40;
  posY = y + 40;
  rect.setPos(x, y);
}

p30kG::Button &p30kG::Button::draw() {
  if (nowColor == U"0") {
    if (isArea == U"0") {
      rect.draw(Color(255, 255, 255));
    } else if (isArea == U"1") {
      rect.draw(Color(234, 145, 152));
    } else if (isArea == U"2") {
      rect.draw(Color(157, 204, 224));
    }
  } else if (nowColor == U"1") {
    rect.draw(Color(255, 0, 0));
  } else if (nowColor == U"2") {
    rect.draw(Color(0, 0, 255));
  }

  font(point).draw(pos, Palette::Black);

  return *this;
}

p30kG::Button &p30kG::Button::draw(bool onAgent) {
  if (nowColor == U"0") {
    if (isArea == U"0") {
      rect.draw(Color(255, 255, 255));
    } else if (isArea == U"1") {
      rect.draw(Color(234, 145, 152));
    } else if (isArea == U"2") {
      rect.draw(Color(157, 204, 224));
    }
  } else if (nowColor == U"1") {
    rect.draw(Color(255, 0, 0));
  } else if (nowColor == U"2") {
    rect.draw(Color(0, 0, 255));
  }

  if (onAgent) {
    Circle(posX, posY, 10).draw(Palette::Black);
  } else {
    Circle(posX, posY, 10).draw(Palette::White);
  }
  font(point).draw(pos, Palette::Black);

  return *this;
}

bool p30kG::Button::isClick() {
  return rect.leftClicked();
}
