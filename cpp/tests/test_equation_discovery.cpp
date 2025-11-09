#include <cassert>
#include <iostream>

#include "../src/equation_discovery.h"

using namespace equation_discovery;

void test_dataset_creation() {
    std::cout << "Testing DataSet creation... ";
    std::vector<std::vector<double>> data = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    DataSet ds(data);
    assert(ds.rows() == 3);
    assert(ds.cols() == 2);
    assert(ds[0][0] == 1.0);
    assert(ds[0][1] == 2.0);
    std::cout << "PASSED\n";
}

void test_equation_creation() {
    std::cout << "Testing Equation creation... ";
    Equation eq("y = 2*x + 1");
    assert(eq.toString() == "y = 2*x + 1");
    eq.setFitness(0.95);
    assert(eq.fitness() == 0.95);
    std::cout << "PASSED\n";
}

void test_symbolic_regression() {
    std::cout << "Testing SymbolicRegression... ";
    std::vector<std::vector<double>> data = {{1.0, 3.0}, {2.0, 5.0}, {3.0, 7.0}};
    DataSet ds(data);
    SymbolicRegression sr(100, 10);
    Equation eq = sr.discover(ds);
    assert(!eq.toString().empty());
    assert(eq.fitness() >= 0.0 && eq.fitness() <= 1.0);
    std::cout << "PASSED\n";
}

void test_sindy() {
    std::cout << "Testing SINDy... ";
    std::vector<std::vector<double>> data = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    DataSet ds(data);
    SINDy sindy(0.1, 10);
    std::vector<Equation> eqs = sindy.discoverMultiple(ds, 3);
    assert(eqs.size() == 3);
    for (const auto& eq : eqs) {
        assert(!eq.toString().empty());
    }
    std::cout << "PASSED\n";
}

void test_empty_dataset_throws() {
    std::cout << "Testing empty DataSet throws exception... ";
    std::vector<std::vector<double>> empty_data;
    try {
        DataSet ds(empty_data);
        assert(false);  // Should not reach here
    } catch (const std::invalid_argument&) {
        // Expected
    }
    std::cout << "PASSED\n";
}

int main() {
    std::cout << "Running C++ Unit Tests\n";
    std::cout << "======================\n\n";

    test_dataset_creation();
    test_equation_creation();
    test_symbolic_regression();
    test_sindy();
    test_empty_dataset_throws();

    std::cout << "\nAll tests passed!\n";
    return 0;
}
