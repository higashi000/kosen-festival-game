#ifndef GAME_HPP_
#define GAME_HPP_

#include <Siv3D.hpp>
#include "button.hpp"
#include "connector.hpp"
#include <vector>
#include <time.h>
#include <string>
#include "field.hpp"
#include <unistd.h>
#include "action.hpp"

namespace p30kG {
class Game {
  private :
    Connector conn;
    Array<Array<Button>> buttons;
    Font font;
    Font result = Font(100);
    std::vector<bool> isClicked;
    std::vector<Action> actions;
    Rect answerSend;
    Rect fieldUpdate;
    bool canUpdate;
    time_t st;
    int turn;

  public :
    Game();
    bool dispField();
    void finishGame();
    void setFieldData();
    time_t turnSt;
    Field field;
};
}

#endif
