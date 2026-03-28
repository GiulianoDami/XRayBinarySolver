cpp
#include "JsonHandler.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

namespace XRayBinarySolver {
    
    json JsonHandler::loadJsonFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }
        
        json data;
        file >> data;
        return data;
    }
    
    void JsonHandler::saveJsonFile(const std::string& filename, const json& data) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not create file: " + filename);
        }
        
        file << data.dump(4); // 4-space indentation
    }
    
    json JsonHandler::createDefaultConfig() {
        json config;
        config["astrophysical_parameters"] = {
            {"distance_parsecs", 100.0},
            {"temperature_k", 10000.0},
            {"luminosity_sol", 1.0}
        };
        config["observation_data"] = {
            {"exposure_time_seconds", 3600.0},
            {"detector_efficiency", 0.8}
        };
        config["analysis_settings"] = {
            {"confidence_threshold", 0.95},
            {"significance_level", 0.05}
        };
        return config;
    }
    
} // namespace XRayBinarySolver