#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include <Siv3D.hpp>

namespace p30kG {
struct Field {
  public:
    std::vector<int> myMoveDir;
    int width;
    int height;
    Array<Array<String>> point;
    time_t startedAtUnixTime;
    Array<Array<String>> color;
    int agentNum;
    int myTeamID;
    std::vector<std::vector<int>> myAgentData;
    int myTilePoint;
    int myAreaPoint;
    int rivalTeamID;
    std::vector<std::vector<int>> rivalAgentData;
    int rivalTilePoint;
    int rivalAreaPoint;
    String maxTurn;
    String turn;
    Array<Array<String>> areaPointInfo;
};
}

#endif
