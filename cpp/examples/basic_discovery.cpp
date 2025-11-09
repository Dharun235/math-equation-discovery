#include <iostream>

#include "equation_discovery.h"

using namespace equation_discovery;

int main() {
    std::cout << "Math Equation Discovery - C++ Example\n";
    std::cout << "======================================\n\n";

    // Create sample data (simple linear relationship: y = 2x + 1)
    std::vector<std::vector<double>> sample_data;
    for (int i = 0; i < 10; ++i) {
        double x = static_cast<double>(i);
        double y = 2.0 * x + 1.0;
        sample_data.push_back({x, y});
    }

    try {
        DataSet data(sample_data);
        std::cout << "Created dataset with " << data.rows() << " rows and " << data.cols()
                  << " columns\n\n";

        // Test Symbolic Regression
        std::cout << "1. Symbolic Regression\n";
        std::cout << "----------------------\n";
        SymbolicRegression sr(1000, 100);
        Equation sr_eq = sr.discover(data);
        std::cout << "Discovered equation: " << sr_eq.toString() << "\n";
        std::cout << "Fitness: " << sr_eq.fitness() << "\n\n";

        // Test SINDy
        std::cout << "2. SINDy (Sparse Identification)\n";
        std::cout << "---------------------------------\n";
        SINDy sindy(0.1, 10);
        std::vector<Equation> sindy_eqs = sindy.discoverMultiple(data, 3);
        std::cout << "Discovered " << sindy_eqs.size() << " equations:\n";
        for (size_t i = 0; i < sindy_eqs.size(); ++i) {
            std::cout << "  [" << i + 1 << "] " << sindy_eqs[i].toString()
                      << " (fitness: " << sindy_eqs[i].fitness() << ")\n";
        }

        std::cout << "\nEquation discovery completed successfully!\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
