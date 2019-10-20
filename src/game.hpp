#ifndef GAME_HPP_
#define GAME_HPP_

#include <Siv3D.hpp>
#include "button.hpp"
#include "connector.hpp"
#include "field.hpp"

namespace p30kG {
class Game {
  private :
    Connector conn;
    Array<Array<Button>> buttons;
    Field field;
    Font font;

  public :
    Game();
    void dispField();
    void setFieldData();
};
}

#endif
