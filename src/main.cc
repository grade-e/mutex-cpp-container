#include <thread>

#include "SerialHandler.hpp"

int main() {
    SerialHandler serial_handler("/dev/ttyUSB0", 9600);
    if (!serial_handler.open()) {
        std::cerr << "Failed to open serial port." << std::endl;
        return 1;
    }
    std::thread writer1(&SerialHandler::write, &serial_handler, "Message 1");
    std::thread writer2(&SerialHandler::write, &serial_handler, "Message 2");
    std::thread reader(&SerialHandler::read, &serial_handler);

    writer1.join();
    writer2.join();
    reader.join();

    serial_handler.close();
    return 0;
}