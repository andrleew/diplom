#include "arg_reader.h"
#include "utils.h"

#include <string>
#include <cassert>

using namespace NAlgo;

TArgReader::TArgReader(int argc, char* argv[]) {
    for (size_t i = 1; i < argc; ++i) {
        auto s = RemoveAttr(argv[i]);
        ParamsToId.insert({s, i});
        IdToParam.emplace_back(std::move(s));
    }
}

std::string TArgReader::GetOption(char c) const {
    return GetOption(std::to_string(c));
}

bool TArgReader::Has(char c) const {
    return Has(std::to_string(c));
}

bool TArgReader::Has(const std::string& str) const {
    auto it = ParamsToId.find(str);
    return it != ParamsToId.end();
}

std::string TArgReader::GetOption(const std::string& str) const {
    auto it = ParamsToId.find(str);
    assert(it != ParamsToId.end());
    assert(it->second <= IdToParam.size());
    return IdToParam[it->second - 1];
}

bool TArgReader::GetFlag(char c) const {
    return GetFlag(std::to_string(c));
}

bool TArgReader::GetFlag(const std::string& str) const {
    return Has(str);    
}