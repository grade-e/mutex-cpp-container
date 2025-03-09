#pragma once

#include <memory>
#include <mutex>

#include "PortHandler.hpp"
#include "SerialPort.hpp"

class SerialHandler : public PortHandler {
   public:
    SerialHandler(const std::string& port, int baudRate)
        : port_(port), baudRate_(baudRate) {
        serial_ = std::make_unique<SerialPort>(port_, baudRate_);
    }

    bool open() override { return serial_->open(); }
    void close() override { serial_->close(); }
    void write(const std::string& data) override {
        std::lock_guard<std::mutex> lock(serial_mutex_);
        serial_->write(data);
    }
    std::string read() override {
        std::lock_guard<std::mutex> lock(serial_mutex_);
        return serial_->read();
    }

   private:
    std::unique_ptr<SerialPort> serial_;
    std::mutex serial_mutex_;
    std::string port_;
    int baudRate_;
};
