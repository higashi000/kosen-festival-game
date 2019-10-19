#ifdef FIELD_HPP
#define FIELD_HPP

#include <vector>

namespace p30kG {
struct Field {
  std::vector<int> myMoveDir;
  int width;
  int height;
  std::vector<std::vector<int>> point;
  int startedAtUnixTime;
  std::vector<std::vector<int>> color;
  int agentNum;
  int myTeamID;
  std::vector<std::vector<int>> myAgentData;
  int myTilePoint;
  int myAreaPoint;
  int rivalTeamID;
  std::vector<std::vector<int>> rivalAgentData;
  int rivalTilePoint;
  int rivalAreaPoint;
  int maxTurn;
  int turn;
  std::vector<std::vector<int>> areaPointInfo;
};
}

#endif
