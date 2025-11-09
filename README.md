# Math Equation Discovery

An AI-based methodology for discovering governing equations, hidden relationships, and symbolic laws directly from data. Like an automated Kepler or Newton, this system doesn't just solve equations—it discovers them.

## Overview
This project implements various approaches to automated equation discovery in C++, enabling researchers and engineers to:
- Extract symbolic mathematical relationships from observational data
- Discover governing equations of dynamical systems
- Identify physical laws and conservation principles
- Uncover hidden patterns in complex datasets

## Features

- **High-Performance C++ Implementation**: Efficient core algorithms for production use
- **Multiple Approaches**: Symbolic regression, sparse identification (SINDy), neural networks, and genetic programming
- **Diverse Problem Domains**: Pre-configured for dynamical systems, physics, biology, and economics
- **Extensible Architecture**: Easy to add new methods and problem types
- **Comprehensive Testing**: Unit tests and integration tests for all components
- **Modern C++ Standards**: C++17 with clean, maintainable code

## Project Structure

```
math-equation-discovery/
├── cpp/                          # C++ implementation
│   ├── src/                      # Core library source files
│   ├── tests/                    # Unit tests
│   ├── examples/                 # Example programs
│   └── CMakeLists.txt            # Build configuration
├── problems/                     # Problem-specific implementations
│   ├── dynamical_systems/        # Lorenz, double pendulum, etc.
│   ├── physics/                  # Planetary motion, mechanics
│   ├── biology/                  # Population dynamics, biochemical
│   └── economics/                # Market models, growth equations
├── approaches/                   # Different discovery methods
│   ├── symbolic_regression/      # Genetic programming-based
│   ├── sparse_identification/    # SINDy and variants
│   ├── neural_networks/          # Deep learning methods
│   └── genetic_programming/      # GP-based discovery
├── docs/                         # Documentation
├── .clang-format                 # Code formatting rules
└── .gitignore                    # Git ignore patterns

```

## Approaches

### 1. Symbolic Regression
Uses genetic programming to evolve mathematical expressions that fit the data. Best for discovering explicit functional forms.

### 2. Sparse Identification of Nonlinear Dynamics (SINDy)
Identifies sparse governing equations from time-series data. Excellent for dynamical systems with polynomial or trigonometric terms.

### 3. Neural Network Methods
Leverages deep learning for equation discovery, including physics-informed neural networks (PINNs) and neural symbolic regression.

### 4. Genetic Programming
Evolution-based approach to discover symbolic expressions through crossover, mutation, and selection.

## Getting Started

### Prerequisites

- **C++17** or later
- **CMake 3.15+**
- **clang-format** (for code formatting)
- A C++ compiler: GCC 7+, Clang 5+, or MSVC 2019+

### Building the Project

```bash
cd cpp
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Running Tests

```bash
cd cpp/build
make test
# Or run the test executable directly
./test_equation_discovery
```

### Running Examples

```bash
cd cpp/build
./basic_discovery
```

## Usage Examples

### Example 1: Discovering Equations with SINDy

```cpp
#include "equation_discovery.h"

int main() {
    // Create sample data
    std::vector<std::vector<double>> data = /* your time-series data */;
    DataSet dataset(data);
    
    // Use SINDy to discover equations
    SINDy sindy(0.1, 10);  // threshold=0.1, max_iter=10
    std::vector<Equation> equations = sindy.discoverMultiple(dataset, 3);
    
    // Print discovered equations
    for (const auto& eq : equations) {
        std::cout << eq.toString() << " (fitness: " << eq.fitness() << ")\n";
    }
    
    return 0;
}
```

### Example 2: Symbolic Regression

```cpp
#include "equation_discovery.h"

int main() {
    // Load data
    std::vector<std::vector<double>> data = /* your data */;
    DataSet dataset(data);
    
    // Run symbolic regression
    SymbolicRegression sr(1000, 100);  // population=1000, generations=100
    Equation eq = sr.discover(dataset);
    
    std::cout << "Discovered equation: " << eq.toString() << std::endl;
    std::cout << "Fitness: " << eq.fitness() << std::endl;
    
    return 0;
}
```

## Problem Domains

### Dynamical Systems
- Lorenz attractor
- Double pendulum
- Van der Pol oscillator
- Coupled oscillators

### Physics
- Planetary motion (Kepler's laws)
- Spring-mass systems
- Projectile motion
- Wave equations

### Biology
- Population dynamics (Lotka-Volterra)
- Enzyme kinetics (Michaelis-Menten)
- Gene regulatory networks
- Epidemic models (SIR, SEIR)

### Economics
- Market equilibrium
- Growth models
- Supply-demand dynamics

## Code Formatting

C++ code follows the project's clang-format style. Format your code before committing:

```bash
clang-format -i cpp/src/**/*.cpp cpp/src/**/*.h
```

## Testing

Run all tests:

```bash
# C++
cd cpp/build && make test
```

## Contributing

Contributions are welcome! Please:
1. Fork the repository
2. Create a feature branch
3. Make your changes with tests
4. Ensure all tests pass
5. Format your code with clang-format
6. Submit a pull request

## References

- Brunton, S. L., et al. (2016). "Discovering governing equations from data by sparse identification of nonlinear dynamical systems." PNAS.
- Schmidt, M., & Lipson, H. (2009). "Distilling free-form natural laws from experimental data." Science.
- Cranmer, M., et al. (2020). "Discovering symbolic models from deep learning with inductive biases." NeurIPS.

## License

See LICENSE file for details.

## Acknowledgments

This project draws inspiration from the work of automated scientists and equation discovery pioneers who have shown that machines can rediscover fundamental laws of nature from data alone.
