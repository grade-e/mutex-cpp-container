#pragma once

#include <iostream>
#include <string>

using namespace std;

class SerialPort {
   public:
    SerialPort(const string& port, int baudRate)
        : port_(port), baudRate_(baudRate), isOpen_(false) {}

    bool open() {
        isOpen_ = true;
        cout << "[Serial_] " << "Open: " << port_ << ", baudrate: " << baudRate_
             << endl;
        return isOpen_;
    }

    void close() {
        isOpen_ = false;
        cout << "[Serial_] " << "Close: " << port_ << endl;
    }

    void write(const string& data) {
        cout << "[Serial_] " << "Write: " << data << endl;
    }

    string read() {
        string buffer = "Dummy Data";
        cout << "[Serial_] " << "Read: " << buffer << endl;
        return buffer;
    }

   private:
    string port_;
    int baudRate_;
    bool isOpen_;
};
