PROJECT_NAME: XRayBinarySolver

# XRayBinarySolver

A C++ application that analyzes stellar binary systems to identify potential hidden companions based on X-ray emission patterns, inspired by the discovery of Gamma Cassiopeiae's white dwarf companion.

## Description

This project implements a computational model to detect and analyze binary star systems where one component is a white dwarf accreting matter from a visible companion star. By analyzing X-ray emission data and orbital mechanics, the program helps identify candidates for hidden stellar companions that might be generating extreme X-ray emissions, similar to the 50-year mystery solved by the XRISM space telescope.

The application uses astrophysical calculations to determine if observed X-ray signatures could indicate the presence of an unseen companion star, particularly focusing on systems where the companion is too faint to be directly observed but significantly affects the X-ray output.

## Installation

### Prerequisites
- C++17 compatible compiler (GCC 7+, Clang 5+, or MSVC 2017+)
- CMake 3.10 or higher

### Building the Project

```bash
# Clone the repository
git clone https://github.com/yourusername/XRayBinarySolver.git
cd XRayBinarySolver

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Run tests (optional)
make test
```

### Dependencies
The project uses only standard C++ libraries and does not require external dependencies.

## Usage

```cpp
#include "XRayBinarySolver.h"

int main() {
    // Create solver instance
    XRayBinarySolver solver;
    
    // Define parameters for a suspected binary system
    BinarySystemParams params;
    params.primaryMass = 15.0;        // Solar masses
    params.secondaryMass = 0.8;       // Solar masses  
    params.orbitalPeriod = 2.5;       // Days
    params.xrayLuminosity = 1e32;     // Erg/s
    params.distance = 150.0;          // Parsecs
    
    // Analyze the system
    auto result = solver.analyzeSystem(params);
    
    // Display results
    std::cout << "System Analysis Results:" << std::endl;
    std::cout << "Potential White Dwarf Companion: " 
              << (result.hasWhiteDwarf ? "YES" : "NO") << std::endl;
    std::cout << "Accretion Rate: " << result.accretionRate << " solar masses/year" << std::endl;
    std::cout << "X-Ray Efficiency: " << result.xrayEfficiency << "%" << std::endl;
    
    return 0;
}
```

### Command Line Interface

```bash
# Run analysis with default parameters
./xray_solver

# Run analysis with custom input file
./xray_solver --input system_data.json

# Generate report
./xray_solver --report --output analysis_report.txt
```

## Features

- **Binary System Analysis**: Calculates orbital mechanics and X-ray emission properties
- **White Dwarf Detection**: Identifies potential hidden companions based on X-ray signatures
- **Accretion Modeling**: Computes mass transfer rates and energy output
- **Astrophysical Calculations**: Implements standard formulas for stellar systems
- **JSON Input/Output**: Supports configuration files for batch processing
- **Report Generation**: Creates detailed analysis reports

## Example Output

```
Analyzing Binary System:
Primary Mass: 15.00 Msun
Secondary Mass: 0.80 Msun
Orbital Period: 2.50 days
X-Ray Luminosity: 1.00e+32 erg/s

Analysis Results:
✓ Potential White Dwarf Companion: YES
✓ Accretion Rate: 1.23e-07 Msun/year
✓ X-Ray Efficiency: 42.3%
✓ System Stability: UNSTABLE
```

## Algorithm Overview

The core algorithm follows these steps:
1. Parse input parameters for the binary system
2. Calculate orbital characteristics using Kepler's laws
3. Model accretion disk physics for the white dwarf
4. Compute expected X-ray luminosity based on mass transfer rate
5. Compare with observed X-ray emission to validate companion existence
6. Generate comprehensive analysis report

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a pull request

## License

MIT License - see LICENSE file for details

## Acknowledgments

Inspired by the recent astronomical discovery of Gamma Cassiopeiae's hidden white dwarf companion, which solved a 50-year mystery in stellar astronomy.