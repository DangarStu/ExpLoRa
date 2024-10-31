#include <string>
#include <iostream>
#include "packet.h"
#include "message.h"

// Constructors to create empty packets.
Packet::Packet(Node from, Node to):
    from(from),
    to(to) { }

Packet::Packet(Node from, Node to, uint8_t ttl):
    from(from),
    to(to),
    ttl(ttl) { }

// Add a new message to this packet.
void Packet::addMessage(const Message& message) {
    payload.push_back(message);  // Add message by copying
}

// Return the entire packet as a string ready for transmission.
std::string Packet::toString() {
    // From, To + loop through all messages.
    std::string packetString = from.getDeviceID() + ":" + to.getDeviceID() + ":";
        for (auto thisMessage = payload.begin(); thisMessage != payload.end(); ++thisMessage) {
        packetString += thisMessage->toString();
        if (thisMessage + 1 != payload.end()) {
            packetString += ":";  // Add separator between messages
        }
    }

    return packetString;
}