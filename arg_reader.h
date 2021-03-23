#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace NAlgo {

    class TArgReader{
    public:
        TArgReader(int argc, char* argv[]);
        
    public:
        bool Has(char c) const;
        bool Has(const std::string& str) const;

        std::string GetOption(char c) const;
        std::string GetOption(const std::string& str) const;
        bool GetFlag(char c) const;
        bool GetFlag(const std::string& str) const;
        

    private:
        enum EOption {
            Long,
            Flag,
        };

    private:
        std::unordered_map<std::string, size_t> ParamsToId;
        std::vector<std::string> IdToParam;
    };
    
    
} // namespace NAlgo
