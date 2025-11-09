# Math Equation Discovery - Documentation

Welcome to the comprehensive documentation for the Math Equation Discovery project.

## Table of Contents

1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Core Concepts](#core-concepts)
4. [API Reference](#api-reference)
5. [Tutorials](#tutorials)
6. [Best Practices](#best-practices)

## Introduction

This project provides a C++ framework for automated discovery of mathematical equations and governing laws from observational data. It implements multiple approaches including symbolic regression, sparse identification (SINDy), genetic programming, and neural network methods.

## Getting Started

### Installation

```bash
git clone https://github.com/Dharun235/math-equation-discovery.git
cd math-equation-discovery/cpp
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Quick Start Example

```cpp
#include "equation_discovery.h"
#include <iostream>

int main() {
    // Create sample data
    std::vector<std::vector<double>> data = {
        {1.0, 3.0},
        {2.0, 5.0},
        {3.0, 7.0}
    };
    
    DataSet dataset(data);
    
    // Discover equation using symbolic regression
    SymbolicRegression sr;
    Equation eq = sr.discover(dataset);
    
    std::cout << eq.toString() << std::endl;
    return 0;
}
```

## Core Concepts

### DataSet

The `DataSet` class represents input data for equation discovery. It stores data in a 2D array format where each row is an observation.

```cpp
std::vector<std::vector<double>> data = {{1, 2}, {3, 4}};
DataSet ds(data);
std::cout << "Rows: " << ds.rows() << ", Cols: " << ds.cols() << std::endl;
```

### Equation

The `Equation` class represents a discovered mathematical relationship. It stores:
- The symbolic expression as a string
- Fitness score (how well it fits the data)
- Methods to evaluate the equation with new inputs

```cpp
Equation eq("y = 2*x + 1");
eq.setFitness(0.95);
std::cout << "Expression: " << eq.toString() << std::endl;
std::cout << "Fitness: " << eq.fitness() << std::endl;
```

### Discovery Methods

All discovery methods inherit from the `DiscoveryMethod` interface:

```cpp
class DiscoveryMethod {
public:
    virtual Equation discover(const DataSet& data) = 0;
    virtual std::vector<Equation> discoverMultiple(const DataSet& data, size_t n) = 0;
};
```

#### Symbolic Regression

Uses genetic programming to evolve mathematical expressions.

```cpp
SymbolicRegression sr(1000, 100);  // population, generations
Equation eq = sr.discover(dataset);
```

#### SINDy (Sparse Identification)

Identifies sparse governing equations from time-series data.

```cpp
SINDy sindy(0.1, 10);  // threshold, max_iter
std::vector<Equation> eqs = sindy.discoverMultiple(dataset, 3);
```

## API Reference

### DataSet Class

```cpp
class DataSet {
public:
    DataSet(const std::vector<std::vector<double>>& data);
    size_t rows() const;
    size_t cols() const;
    const std::vector<double>& operator[](size_t i) const;
};
```

### Equation Class

```cpp
class Equation {
public:
    Equation(const std::string& expression);
    std::string toString() const;
    double evaluate(const std::vector<double>& inputs) const;
    double fitness() const;
    void setFitness(double f);
};
```

### SymbolicRegression Class

```cpp
class SymbolicRegression : public DiscoveryMethod {
public:
    SymbolicRegression(size_t population_size = 1000, 
                      size_t generations = 100);
    Equation discover(const DataSet& data) override;
    std::vector<Equation> discoverMultiple(const DataSet& data, 
                                          size_t n) override;
};
```

### SINDy Class

```cpp
class SINDy : public DiscoveryMethod {
public:
    SINDy(double threshold = 0.1, size_t max_iter = 10);
    Equation discover(const DataSet& data) override;
    std::vector<Equation> discoverMultiple(const DataSet& data, 
                                          size_t n) override;
};
```

## Tutorials

### Tutorial 1: Discovering a Simple Linear Relationship

```cpp
#include "equation_discovery.h"

int main() {
    // Generate data: y = 2x + 1
    std::vector<std::vector<double>> data;
    for (int i = 0; i < 10; i++) {
        double x = static_cast<double>(i);
        double y = 2.0 * x + 1.0;
        data.push_back({x, y});
    }
    
    DataSet ds(data);
    SymbolicRegression sr(1000, 50);
    Equation eq = sr.discover(ds);
    
    std::cout << "Discovered: " << eq.toString() << std::endl;
    std::cout << "Fitness: " << eq.fitness() << std::endl;
    
    return 0;
}
```

### Tutorial 2: Discovering Dynamical System Equations

```cpp
#include "equation_discovery.h"

int main() {
    // Load time-series data with derivatives
    // X: state variables, X_dot: time derivatives
    std::vector<std::vector<double>> X = /* load data */;
    std::vector<std::vector<double>> X_dot = /* compute derivatives */;
    
    DataSet state_data(X);
    DataSet derivative_data(X_dot);
    
    // Use SINDy to identify governing equations
    SINDy sindy(0.1, 10);
    std::vector<Equation> equations = sindy.discoverMultiple(state_data, 3);
    
    for (size_t i = 0; i < equations.size(); i++) {
        std::cout << "Equation " << i+1 << ": " 
                  << equations[i].toString() << std::endl;
    }
    
    return 0;
}
```

## Best Practices

### Data Preparation

1. **Normalize Data**: Scale features to similar ranges
2. **Remove Outliers**: Clean extreme values that may skew results
3. **Sufficient Samples**: Ensure adequate data for robust discovery
4. **Multiple Trajectories**: For dynamical systems, use multiple initial conditions

### Parameter Selection

**Symbolic Regression**:
- Population size: 500-2000 (larger for complex problems)
- Generations: 50-200 (monitor convergence)

**SINDy**:
- Threshold: 0.01-0.5 (lower for cleaner data)
- Max iterations: 5-20 (usually converges quickly)

### Validation

1. **Train-Test Split**: Reserve data for validation
2. **Cross-Validation**: Use k-fold cross-validation
3. **Physical Plausibility**: Check if results make sense
4. **Simplicity**: Prefer simpler equations (Occam's Razor)

### Performance Optimization

1. **Use appropriate data types**: Consider float vs double
2. **Parallelize fitness evaluation**: OpenMP or TBB
3. **Cache repeated computations**: Memoization
4. **Profile code**: Identify bottlenecks

### Code Style

Follow the project's clang-format configuration:

```bash
clang-format -i your_file.cpp
```

## Troubleshooting

### Common Issues

**Problem**: Equations are too complex
- **Solution**: Increase sparsity threshold, add parsimony pressure

**Problem**: Poor convergence
- **Solution**: Increase population/generations, improve data quality

**Problem**: Overfitting
- **Solution**: Use cross-validation, regularization, simpler function sets

## Contributing

See the main README for contribution guidelines.

## References

1. Brunton, S. L., et al. (2016). "Discovering governing equations from data." PNAS.
2. Schmidt, M., & Lipson, H. (2009). "Distilling free-form natural laws." Science.
3. Cranmer, M., et al. (2020). "Discovering symbolic models from deep learning." NeurIPS.

## License

See LICENSE file in the repository root.
