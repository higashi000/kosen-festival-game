#include "action.hpp"

namespace p30kG {
Action::Action(int x, int y, int id, std::string move) {
  dx = x;
  dy = y;
  agentID = id;
  moveType = move;
}
} //namespace p30kG
