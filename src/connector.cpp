#include "connector.hpp"
namespace p30kG {

void Connector::getFieldData() {
  int sockfd;
  sockaddr_in addr;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(8081);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in));

  char sendStr[4] = "sf";
  char rsvData[1024];

  write(sockfd, sendStr, 4);
  read(sockfd, rsvData, 1024);
  close(sockfd);

  std::cout << rsvData << std::endl;
}

} // namespace p30kG
