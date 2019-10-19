#ifndef CONNECTOR_HPP_
#define CONNECTOR_HPP_

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "field.hpp"

namespace p30kG {
class Connector {

  public:
    void getFieldData();
    void sendResult();
};

} // namespace p30kG
#endif
