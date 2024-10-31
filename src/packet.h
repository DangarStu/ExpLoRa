#ifndef PACKET_H
#define PACKET_H

#include <string>
#include <node.h>
#include <message.h>
#include <cstdint>

class Packet {
public:
    // Constructor
    Packet(Node from, Node to);
    Packet(Node from, Node to, uint8_t ttl);

    // Method to get the two-letter country code as a string
    std::string toString();
    void addMessage(Message message);

private:
    Node from;
    Node to;
    uint8_t messageCount = 0;
    Message *payload[50];
    uint8_t ttl = 5;
};

#endif // PACKET_H
