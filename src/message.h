#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <cstdint>

class Message {
    public:
        // Constructor
        Message(std::string opCode, uint8_t device, uint8_t value);
        Message(std::string opCode, uint8_t device, uint8_t value, uint8_t priority);

        std::string toString() const;
    private:
        std::string opCoode; 
        uint8_t device;
        uint8_t value;
        uint8_t priority;
};

#endif // MESSAGE_H
