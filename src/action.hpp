#ifndef ACTION_HPP_
#define ACTION_HPP_

#include <string>

namespace p30kG {
struct Action {
  int dx;
  int dy;
  int agentID;
  std::string moveType;

  Action();
  Action(int x, int y, int id, std::string move);
};
} // namespace p30kG

#endif
