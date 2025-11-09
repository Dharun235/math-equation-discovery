#ifndef EQUATION_DISCOVERY_H
#define EQUATION_DISCOVERY_H

#include <string>
#include <vector>

namespace equation_discovery {

// Base class for data representation
class DataSet {
public:
    DataSet(const std::vector<std::vector<double>>& data);
    size_t rows() const { return data_.size(); }
    size_t cols() const { return data_.empty() ? 0 : data_[0].size(); }
    const std::vector<double>& operator[](size_t i) const { return data_[i]; }

private:
    std::vector<std::vector<double>> data_;
};

// Base class for equation representation
class Equation {
public:
    Equation(const std::string& expression);
    std::string toString() const { return expression_; }
    double evaluate(const std::vector<double>& inputs) const;
    double fitness() const { return fitness_; }
    void setFitness(double f) { fitness_ = f; }

private:
    std::string expression_;
    double fitness_;
};

// Abstract base class for discovery methods
class DiscoveryMethod {
public:
    virtual ~DiscoveryMethod() = default;
    virtual Equation discover(const DataSet& data) = 0;
    virtual std::vector<Equation> discoverMultiple(const DataSet& data, size_t n) = 0;
};

// Symbolic Regression using genetic programming
class SymbolicRegression : public DiscoveryMethod {
public:
    SymbolicRegression(size_t population_size = 1000, size_t generations = 100);
    Equation discover(const DataSet& data) override;
    std::vector<Equation> discoverMultiple(const DataSet& data, size_t n) override;

private:
    size_t population_size_;
    size_t generations_;
};

// SINDy (Sparse Identification of Nonlinear Dynamics)
class SINDy : public DiscoveryMethod {
public:
    SINDy(double threshold = 0.1, size_t max_iter = 10);
    Equation discover(const DataSet& data) override;
    std::vector<Equation> discoverMultiple(const DataSet& data, size_t n) override;

private:
    double threshold_;
    size_t max_iter_;
};

}  // namespace equation_discovery

#endif  // EQUATION_DISCOVERY_H
