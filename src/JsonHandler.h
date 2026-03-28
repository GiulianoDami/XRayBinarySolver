cpp
#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <string>
#include <nlohmann/json.hpp>

// Assuming these classes are defined elsewhere in the project
class BinarySystemParams;
class AnalysisResult;

class JsonHandler {
public:
    // Load parameters from JSON file
    static bool loadFromFile(const std::string& filename, BinarySystemParams& params);
    
    // Save analysis report to JSON file
    static bool saveReport(const std::string& filename, const AnalysisResult& result);
};

#endif // JSONHANDLER_H