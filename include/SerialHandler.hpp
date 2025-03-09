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

    bool open() override;
    void close() override;
    void write(const std::string& data) override;
    std::string read() override;

   private:
    std::unique_ptr<SerialPort> serial_;
    std::mutex serial_mutex_;
    std::string port_;
    int baudRate_;
};

bool SerialHandler::open() { return serial_->open(); }

void SerialHandler::close() { serial_->close(); }

void SerialHandler::write(const std::string& data) {
    std::lock_guard<std::mutex> lock(serial_mutex_);
    serial_->write(data);
}

std::string SerialHandler::read() {
    std::lock_guard<std::mutex> lock(serial_mutex_);
    return serial_->read();
}