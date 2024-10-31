#include <string>
#include <iostream>
#include <country.h>
#include <node.h>

Node::Node(
    std::string nodeName,
    CountryCode countryCode,
    char nodeRegion,
    char nodeId) :
        nodeName(nodeName),
        country(countryCode),
        nodeRegion(nodeRegion),
        nodeId(nodeId) { 
        }

Node::Node(
    std::string nodeName,
    CountryCode countryCode,
    char nodeRegion,
    char nodeId,
    bool hasWIFI) :
        nodeName(nodeName),
        country(countryCode),
        nodeRegion(nodeRegion),
        nodeId(nodeId),
        hasWIFI(hasWIFI) { 
        }

Node::Node(
    std::string nodeName,
    CountryCode countryCode,
    char nodeRegion,
    char nodeId,
    bool hasWIFI,
    bool hasCANBus) :
        nodeName(nodeName),
        country(countryCode),
        nodeRegion(nodeRegion),
        nodeId(nodeId),
        hasWIFI(hasWIFI),
        hasCANBus(hasCANBus) { }

std::string Node::getDeviceName() const {
    return nodeName;
}

std::string Node::getDeviceID() const {
    return country.toString() + nodeRegion + nodeId;
}
