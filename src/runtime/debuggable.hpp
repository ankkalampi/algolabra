#pragma once

#include <any>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
namespace debug
{

struct Debuggable {
    std::unordered_map<std::string, void*> properties;
    std::string debugName;

    void addDebugProperty(std::string name, void* property)
    {
        properties.insert({name, property});
    }

    void addDebugName(std::string name) { debugName = name; }

    void printDebugInfo() { printinfo(""); }

    void printDebugInfo(std::string message) { printinfo(message); }

    void printinfo(std::string message)
    {
        std::cout << "-----------------\x1b[32m" << debugName
                  << "\x1b[0m-----------------" << std::endl;
        if (message != "") {
            std::cout << "\x1b[20mmessage: " << message << "\x1b[0m"
                      << std::endl;
        }

        std::cout << "ADDRESS: " << this << std::endl;
        std::cout << std::endl;
        for (std::pair<std::string, void*> property : properties) {
            if (property.second == nullptr) {
                std::cout << property.first << ": NULL POINTER!!!" << std::endl;
            } else {
                std::cout << property.first << ": " << property.second
                          << std::endl;
            }
        }

        std::cout << "-----------------";
        for (int i = 0; i < debugName.size(); ++i) {
            std::cout << "-";
        }

        std::cout << "-----------------" << std::endl;
    }
};
}  // namespace debug
