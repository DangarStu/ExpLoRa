#include <string>
#include <iostream>
#include <message.h>

Message::Message(OpCode opCode, uint8_t device, uint8_t value):
    opCode(opCode),
    device(device),
    value(value) { }

Message::Message(OpCode opCode, uint8_t device, uint8_t value, uint8_t priority):
    opCode(opCode),
    device(device),
    value(value),
    priority(priority) { }

const std::unordered_map<OpCode, std::string> opcodeMap = {
    {OpCode::Push, "PSH"},
    {OpCode::Set, "SET"}
};

std::string opCodeToString(OpCode opCode) {
    return opcodeMap.at(opCode);
}

char* Message::toString() const {
    // Buffer to build the C-style string into
    char buffer[20];

    sprintf(buffer, "%s%u%u%u", opCodeToString(opCode).c_str(), device, value, priority);
    return buffer;
}

