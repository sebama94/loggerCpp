#include "loggerCpp/networkLogSink.hpp"
#include <iostream>

NetworkLogSink::NetworkLogSink(std::string_view url) : url_(url) {}

void NetworkLogSink::write(const utils::LogEvent& event) {
    // TODO: implement actual network transport (HTTP, syslog-over-UDP, etc.)
    (void)event;
    std::cerr << "Warning: NetworkLogSink not yet implemented (target: " << url_ << ")\n";
}