#pragma once

#include <string>

class PortHandler {
   public:
    virtual bool open() = 0;
    virtual void close() = 0;
    virtual void write(const std::string& data) = 0;
    virtual std::string read() = 0;
};
