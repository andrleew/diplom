#include "utils.h"
#include <iostream>

void PrintError(const std::string& message) {
    std::cerr << "ERROR\t" << message << "\n";
}

void PrintWarn(const std::string& message) {
    std::cerr << "WARN\t" << message << "\n";
}

void PrintInfo(const std::string& message) {
    std::cout << "INFO\t" << message << "\n";
}

void PrintDebug(const std::string& message) {
#ifdef DEBUG
    std::cerr << "DEBUG\t" << message << "\n";
#endif
}

void Log(ELogLevel ll, const std::string&& str, size_t line, const std::string& file) {
    std::string message = std::string("[") + file + ":" + std::to_string(line) + "] -> " + str;
    switch (ll) {
    case ELogLevel::INFO:
        PrintInfo(message);
        break;
    case ELogLevel::WARN:
        PrintWarn(message);
        break;
    case ELogLevel::ERROR:
        PrintError(message);
        break;
    case ELogLevel::DEBUG:
        PrintDebug(message);
        break;
    default:
        LOG(ELogLevel::ERROR, "unknown log level");
    }
}