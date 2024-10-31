#ifndef NODE_H
#define NODE_H

#include <string>
#include <country.h>

class Node {
public:
    // Constructors
    Node(
        std::string nodeName,
        CountryCode countryCode,
        char nodeRegion,
        char nodeId);

    Node(
        std::string nodeName,
        CountryCode countryCode,
        char nodeRegion,
        char nodeId,
        bool hasWIFI);

    Node(
        std::string nodeName,
        CountryCode countryCode,
        char nodeRegion,
        char nodeId,
        bool hasWIFI,
        bool hasCANBus);

    // Methods to get the devices information
    std::string getDeviceName() const;
    std::string getDeviceID() const;

    bool hasWIFI =  false;
    bool hasCANBus =  false;
private:
    Country country;
    std::string nodeName;
    char nodeRegion = '0';
    char nodeId = '0';

};

#endif // NODE_H
