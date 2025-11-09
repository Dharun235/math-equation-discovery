# Biology Problems

This directory contains implementations for discovering mathematical models of biological systems from experimental data.

## Overview

Biological systems often follow complex dynamics that can be described mathematically. Automated equation discovery can reveal:
- Population dynamics
- Biochemical reaction networks
- Evolutionary dynamics
- Epidemiological models
- Gene regulatory networks

## Problem Domains

### 1. Population Dynamics

**Lotka-Volterra (Predator-Prey)**
```
dx/dt = αx - βxy    (prey)
dy/dt = δxy - γy    (predator)
```

**Logistic Growth**
```
dN/dt = rN(1 - N/K)
```

**Competition Models**
- Interspecific competition
- Resource competition
- Niche dynamics

### 2. Enzyme Kinetics

**Michaelis-Menten Equation**
```
v = (Vmax * [S]) / (Km + [S])
```

**Competitive Inhibition**
**Allosteric Regulation**

### 3. Epidemic Models

**SIR Model**
```
dS/dt = -βSI
dI/dt = βSI - γI
dR/dt = γI
```

**SEIR Model** (with Exposed state)
**SIS Model** (Susceptible-Infected-Susceptible)

### 4. Gene Regulatory Networks

**Hill Functions**
```
f(x) = x^n / (K^n + x^n)
```

**Toggle Switches**
**Oscillatory Networks**

### 5. Cell Growth and Division

- Cell cycle dynamics
- Tumor growth models
- Tissue development

## Discovery Strategies

### Time-Series Data
SINDy works exceptionally well for biological time-series:
- Population counts over time
- Concentration measurements
- Gene expression levels

### Dose-Response Curves
Symbolic regression for fitting:
- Drug response curves
- Enzyme kinetics
- Receptor binding

### Spatial Patterns
For reaction-diffusion systems:
- Pattern formation
- Morphogen gradients
- Turing patterns

## Data Considerations

**Biological Data Challenges**
- High noise levels
- Missing data points
- Batch effects
- Measurement limitations

**Solutions**
- Use ensemble methods
- Apply smoothing/filtering
- Multiple replicates
- Robust regression techniques

## Example: Discovering Logistic Growth

```cpp
#include "biology_discovery.h"

// Generate logistic growth data
std::vector<std::vector<double>> data;
double r = 0.5, K = 100.0, N0 = 5.0;
double dt = 0.1;

for (int i = 0; i < 100; i++) {
    double t = i * dt;
    double N = K / (1 + (K/N0 - 1) * exp(-r*t));
    double dN_dt = r * N * (1 - N/K);
    data.push_back({N, dN_dt});
}

DataSet dataset(data);
SINDy sindy(0.05, 10);
Equation eq = sindy.discover(dataset);

std::cout << "Discovered growth equation: " << eq.toString() << std::endl;
// Expected: dN/dt = r*N - (r/K)*N^2
```

## Biological Interpretation

When equations are discovered:
1. **Identify parameters**: What do coefficients represent?
2. **Check biological realism**: Are values plausible?
3. **Understand mechanisms**: What processes do terms represent?
4. **Predict behavior**: Can model forecast new scenarios?

## Validation Approaches

- **Cross-validation**: Test on held-out data
- **Perturbation experiments**: Predict response to interventions
- **Literature comparison**: Compare with known models
- **Expert review**: Consult domain experts

## Common Equation Forms

**Linear Terms**: Direct effects (growth, decay)
**Quadratic Terms**: Competition, saturation
**Product Terms**: Interactions (predation, catalysis)
**Rational Functions**: Saturation kinetics
**Hill Functions**: Cooperative binding

## Applications

- Drug discovery and pharmacology
- Synthetic biology design
- Ecological management
- Epidemiological forecasting
- Agricultural optimization

## References

- Brunton et al. (2016) "Discovering governing equations"
- Mangan et al. (2016) "Inferring biological networks by sparse identification"
- Hoffmann et al. (2018) "Reactive SINDy"

## Implementation Status

- [ ] Lotka-Volterra system
- [ ] Logistic growth
- [ ] Michaelis-Menten kinetics
- [ ] SIR epidemic model
- [ ] Gene regulatory networks
- [ ] Parameter estimation tools
- [ ] Uncertainty quantification
