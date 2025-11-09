# Dynamical Systems

This directory contains implementations and examples for discovering governing equations of dynamical systems from time-series data.

## Overview

Dynamical systems describe how a system evolves over time according to fixed rules. Discovering these rules from observational data is a fundamental challenge in science and engineering.

## Included Systems

### 1. Lorenz System
A chaotic system describing atmospheric convection:
```
dx/dt = σ(y - x)
dy/dt = x(ρ - z) - y
dz/dt = xy - βz
```

### 2. Double Pendulum
A classic example of chaotic motion in mechanics.

### 3. Van der Pol Oscillator
A non-conservative oscillator with non-linear damping:
```
d²x/dt² - μ(1 - x²)dx/dt + x = 0
```

### 4. Coupled Oscillators
Systems of interconnected harmonic oscillators.

## Discovery Methods

The following approaches work well for dynamical systems:

- **SINDy**: Best for polynomial and trigonometric terms
- **Neural Networks**: Good for complex, high-dimensional systems
- **Symbolic Regression**: Discovers arbitrary functional forms

## Data Requirements

For accurate equation discovery:
- High-quality time-series measurements
- Sufficient temporal resolution
- Multiple trajectories with different initial conditions
- Low measurement noise (or use noise-robust methods)

## Example Usage

```python
from problems.dynamical_systems import LorenzSystem
from approaches.sparse_identification import SINDy

# Generate data
lorenz = LorenzSystem()
X, X_dot = lorenz.generate_data(n_points=1000)

# Discover equations
sindy = SINDy(threshold=0.1)
equations = sindy.fit(X, X_dot)
print(equations)
```

## References

- Brunton, S. L., et al. (2016). "Discovering governing equations from data." PNAS
- Strogatz, S. H. (2015). "Nonlinear Dynamics and Chaos"
