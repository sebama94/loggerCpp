#include "loggerCpp/networkLogSink.hpp"

NetworkLogSink::NetworkLogSink(std::string_view /*url*/) {
    // TODO: implement TCP/UDP/HTTP transport
}

void NetworkLogSink::write(const utils::LogEvent& /*event*/) {
    // TODO: implement network logging
    // Do NOT throw here — write() is called from a noexcept context.
}
