#pragma once

#include <cstdlib>
#include <string>

template<class T>
inline T Sqr(const T&& t) {
    return t * t;
}

enum ELogLevel {
    INFO,
    WARN,
    ERROR,
    DEBUG,
};

void Log(ELogLevel ll, const std::string&& str, size_t line, const std::string& file);

#define LOG(logLevel, message) \
    Log(logLevel, message, __LINE__, __FILE__)


std::string RemoveAttr(const std::string& str) {
    std::string s;
    bool has_found = false;
    for (const auto& c : str) {
        if (c != '-') has_found = true;
        if (has_found) s.push_back(c);
    }
    return s;
}