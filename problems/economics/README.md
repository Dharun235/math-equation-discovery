# Economics Problems

This directory contains implementations for discovering economic models and relationships from market data and economic indicators.

## Overview

Economic systems exhibit complex dynamics that can be modeled mathematically. Automated equation discovery can reveal:
- Supply and demand relationships
- Growth and business cycle dynamics
- Market equilibrium conditions
- Investment and consumption patterns
- Economic policy effects

## Problem Domains

### 1. Supply and Demand

**Basic Relationships**
- Price elasticity of demand
- Supply curves
- Market equilibrium
- Consumer surplus

**Equilibrium Conditions**
```
Qd = Qs
where Qd = demand quantity, Qs = supply quantity
```

### 2. Growth Models

**Solow Growth Model**
```
dK/dt = sY - δK
Y = AK^α L^(1-α)
```

**Endogenous Growth**
- Knowledge accumulation
- Human capital effects
- Technology spillovers

### 3. Business Cycles

**Investment-Saving Dynamics**
- Accelerator-multiplier models
- Inventory cycles
- Credit cycles

**Oscillatory Behavior**
```
d²Y/dt² + α(dY/dt) + βY = γ
```

### 4. Financial Markets

**Asset Pricing**
- Stock price dynamics
- Option pricing relationships
- Risk-return tradeoffs

**Market Microstructure**
- Order flow dynamics
- Price impact
- Bid-ask spreads

### 5. Macroeconomic Relationships

**Phillips Curve**
- Inflation-unemployment tradeoff
- Expectations-augmented versions

**IS-LM Model**
- Investment-saving equilibrium
- Liquidity preference-money supply

**Okun's Law**
```
ΔY = -c(u - u*)
```
Relating output gap to unemployment

## Discovery Strategies

### For Market Data
- High-frequency time series analysis
- Volatility clustering detection
- Regime-switching identification

### For Aggregate Indicators
- Long-term trend identification
- Cointegration relationships
- Leading indicator discovery

### For Policy Analysis
- Treatment effect estimation
- Structural break detection
- Counterfactual modeling

## Data Considerations

**Economic Data Characteristics**
- Non-stationarity (trends, structural breaks)
- Seasonality and cycles
- Measurement revisions
- Policy interventions

**Preprocessing Steps**
1. Detrending or differencing
2. Seasonal adjustment
3. Outlier handling
4. Stationarity tests

## Example: Discovering Demand Curve

```cpp
#include "economics_discovery.h"

// Generate price-quantity data with elasticity
std::vector<std::vector<double>> data;
double a = 100, b = -2;  // Q = a + b*P

for (double P = 10; P <= 50; P += 2) {
    double Q = a + b * P + random_noise();
    data.push_back({P, Q});
}

DataSet dataset(data);
SymbolicRegression sr(500, 50);
Equation demand_curve = sr.discover(dataset);

std::cout << "Discovered demand: " << demand_curve.toString() << std::endl;
// Expected: Q ≈ 100 - 2*P

// Calculate elasticity at P = 20
double elasticity = -2 * 20 / (100 - 2 * 20);
std::cout << "Price elasticity: " << elasticity << std::endl;
```

## Economic Interpretation

When equations are discovered:

1. **Parameter Meaning**: 
   - Slopes: marginal effects
   - Intercepts: baseline levels
   - Coefficients: elasticities, multipliers

2. **Economic Validity**:
   - Sign constraints (e.g., downward demand)
   - Magnitude plausibility
   - Theoretical consistency

3. **Policy Implications**:
   - Predict intervention effects
   - Optimal policy design
   - Welfare analysis

## Common Functional Forms

**Linear**: Direct proportional relationships
```
Y = α + βX
```

**Log-Linear**: Constant elasticity
```
log(Y) = α + β*log(X)
```

**Cobb-Douglas**: Production functions
```
Y = A*K^α*L^β
```

**CES**: Constant elasticity of substitution
```
Y = [αK^ρ + (1-α)L^ρ]^(1/ρ)
```

**Exponential Growth**:
```
Y = Y₀*e^(rt)
```

## Validation Methods

- **Out-of-sample forecasting**: Future data prediction
- **Cross-validation**: Hold-out testing
- **Economic theory**: Consistency with theory
- **Policy experiments**: Natural experiments
- **Comparative statics**: Parameter changes

## Applications

- **Policy Design**: Optimal tax/subsidy levels
- **Forecasting**: GDP, inflation, unemployment
- **Risk Management**: Portfolio optimization
- **Market Analysis**: Price discovery mechanisms
- **Development Economics**: Growth determinants

## Challenges

- **Causality vs Correlation**: Distinguishing causal effects
- **Endogeneity**: Simultaneous determination
- **Structural Changes**: Parameter instability
- **Data Quality**: Measurement errors, revisions
- **Aggregation**: Micro-macro relationships

## References

- Varian (2016) "Causal inference in economics and marketing"
- Athey & Imbens (2019) "Machine learning methods for causal inference"
- Mullainathan & Spiess (2017) "Machine learning: An applied econometric approach"

## Implementation Status

- [ ] Demand/supply curve discovery
- [ ] Growth model estimation
- [ ] Business cycle identification
- [ ] Asset pricing relationships
- [ ] Elasticity computation
- [ ] Instrumental variables
- [ ] Causal inference tools
- [ ] Time series preprocessing
