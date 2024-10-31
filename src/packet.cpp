#include <string>
#include <iostream>
#include "packet.h"
#include "message.h"

Packet::Packet(Node from, Node to):
    from(from),
    to(to) { }

Packet::Packet(Node from, Node to, uint8_t ttl):
    from(from),
    to(to),
    ttl(ttl) { }

void Packet::addMessage(Message message) {
    payload[messageCount] = &message;
}

std::string Packet::toString() {
    // From, To + loop through all messages.
    return from.getDeviceID() + ":" + to.getDeviceID() + ":" + payload[0]->toString();
}