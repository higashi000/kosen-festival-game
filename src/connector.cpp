#include "connector.hpp"
namespace p30kG {

Field Connector::getFieldData() {
  int sockfd;
  Field field;
  sockaddr_in addr;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(8081);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));

  char sendStr[4] = "gf";
  char rsvData[1024];

  write(sockfd, sendStr, 4);
  read(sockfd, rsvData, 1024);
  close(sockfd);

  std::string str = rsvData;

  auto parseStr = split(str, '\n');

  auto widthHeight = split(parseStr[0], ' ');

  field.width = std::stoi(widthHeight[0]);
  field.height = std::stoi(widthHeight[1]);

  field.point = Array<Array<String>>(field.height, Array<String>(field.width));
  for (int i = 0; i < field.height; ++i) {
    auto line = (split(parseStr[1], ';'))[i];
    auto tmp = split(line, ' ');
    for (int j = 0; j < field.width; ++j) {
      field.point[i][j] = s3d::Unicode::Widen(tmp[j]);
    }
  }

  field.startedAtUnixTime = std::stoi(parseStr[2]);
  field.turn = s3d::Unicode::Widen(parseStr[3]);

  field.color = Array<Array<String>>(field.height, Array<String>(field.width));
  for (int i = 0; i < field.height; ++i) {
    auto line = (split(parseStr[4], ';'))[i];
    auto tmp = split(line, ' ');
    for (int j = 0; j < field.width; ++j) {
      field.color[i][j] = s3d::Unicode::Widen(tmp[j]);
    }
  }

  field.agentNum = std::stoi(parseStr[5]);
  field.myTeamID = std::stoi(parseStr[6]);
  field.myAgentData = std::vector<std::vector<int>>(field.agentNum, std::vector<int>(3));
  for (int i = 0; i < field.agentNum; ++i) {
    auto agentData = split(parseStr[7], ';');
    auto tmp = split(agentData[i], ' ');

    field.myAgentData[i][0] = std::stoi(tmp[0]);
    field.myAgentData[i][1] = std::stoi(tmp[1]);
    field.myAgentData[i][2] = std::stoi(tmp[2]);
  }

  auto tmpMyPoint = split(parseStr[8], ' ');
  field.myTilePoint = std::stoi(tmpMyPoint[0]);
  field.myAreaPoint = std::stoi(tmpMyPoint[1]);

  field.rivalTeamID = std::stoi(parseStr[9]);
  field.rivalAgentData = std::vector<std::vector<int>>(field.agentNum, std::vector<int>(3));
  for (int i = 0; i < field.agentNum; ++i) {
    auto agentData = split(parseStr[10], ';');
    auto tmp = split(agentData[i], ' ');

    field.rivalAgentData[i][0] = std::stoi(tmp[0]);
    field.rivalAgentData[i][1] = std::stoi(tmp[1]);
    field.rivalAgentData[i][2] = std::stoi(tmp[2]);
  }
  auto tmpRivalPoint = split(parseStr[11], ' ');
  field.rivalTilePoint = std::stoi(tmpRivalPoint[0]);
  field.rivalAreaPoint = std::stoi(tmpRivalPoint[1]);

  field.maxTurn = s3d::Unicode::Widen(parseStr[12]);

  return field;
}

std::vector<std::string> split(std::string str, char splitChar) {
  std::vector<std::string> parseStr;

  std::stringstream ss(str);

  std::string item;

  while (getline(ss, item, splitChar)) {
    if (!item.empty()) {
      parseStr.push_back(item);
    }
  }

  return parseStr;
}

} // namespace p30kG
