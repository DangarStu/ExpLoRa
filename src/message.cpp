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

const std::unordered_map<OpCode, std::string> opCodeMap = {
    {OpCode::Push, "PSH"},
    {OpCode::Set, "SET"}
};

std::string opCodeToString(OpCode opCode) {
    return opCodeMap.at(opCode);
}

const std::unordered_map<std::string, OpCode> stringToOpcodeMap = {
    {"PSH", OpCode::Push},
    {"SET", OpCode::Set}
};

OpCode stringToOpCode(std::string stringCode) {
    return stringToOpcodeMap.at(stringCode);
}

std::string Message::toString() const {
    // Buffer to build the C-style string into
    char buffer[12];

    sprintf(buffer, "%s,%u,%u,%u:", opCodeToString(opCode).c_str(), device, value, priority);
    return std::string(buffer);
}
