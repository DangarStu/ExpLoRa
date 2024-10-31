#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <cstdint>
#include <unordered_map>

// Value OpCodes:
enum class OpCode {
    Push,
    Set
};

class Message {
    public:
        // Constructor
        Message(OpCode opCode, uint8_t device, uint8_t value);
        Message(OpCode opCode, uint8_t device, uint8_t value, uint8_t priority);
        Message(char* string);

        std::string toString() const;
    private:
        OpCode opCode; 
        uint8_t device;
        uint8_t value;
        uint8_t priority = 5;
};

#endif // MESSAGE_H
