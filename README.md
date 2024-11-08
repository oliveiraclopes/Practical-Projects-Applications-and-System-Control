# Practical Projects: Applications and System Control

This repository contains practical projects developed for the **Applications and System Control** course. The focus of these projects is on designing and implementing digital filters and control applications, primarily using C for microcontrollers. Each project explores different filtering techniques and control mechanisms useful in embedded systems.

## Table of Contents
- [Projects](#projects)
- [Setup and Requirements](#setup-and-requirements)
- [Project Details](#project-details)
  - [Moving Average Filter](#moving-average-filter)
  - [Median Filter](#median-filter)
  - [Proteus Lab](#proteus-lab)

## Projects

1. **Moving Average Filter**: A digital filter that calculates the average of the most recent samples to smooth signal noise.
2. **Median Filter**: A digital filter that selects the median value from a set of samples, useful for removing outlier noise.
3. **Proteus Lab**: Contains files and simulations developed with Proteus software for various control and application experiments.

## Setup and Requirements

These projects are written in C and designed to run on microcontrollers with an 8-bit ADC, specifically using the **PIC16F874** microcontroller. The projects were developed with the following setup:

- **Proteus Software**: For simulating electronic circuits.
- **MPLAB X IDE**: For writing and compiling C code.
- **PIC16F874** microcontroller.
- **ADC Configuration**: 8-bit ADC resolution.

## Project Details

### Moving Average Filter

#### Overview
The Moving Average Filter calculates the average of the last five samples from an analog-to-digital converter (ADC) input to smooth variations in signal data. This filter is commonly used in applications requiring noise reduction in sensor readings.

#### Code Explanation
- **ADC Sampling**: Reads five samples from the ADC channel.
- **Average Calculation**: Computes the arithmetic mean of these samples and outputs the result.
- **Output**: Outputs the calculated average to a digital pin.

#### Directory Structure
- **`Moving_Average_Filter/`**: Contains all source files and simulation files for this filter.
  - `main.c`: Source code for the Moving Average Filter.
  - `README.md`: Project-specific details.

### Median Filter

#### Overview
The Median Filter computes the median of three consecutive samples, reducing the impact of outliers. This filter is effective for applications where occasional large deviations (outliers) might affect data accuracy.

#### Code Explanation
- **ADC Sampling**: Reads 10 samples and repeats the first and last values to provide edge continuity.
- **Median Calculation**: Computes the median of each set of three consecutive samples.
- **Output**: Outputs the median to a digital pin.

#### Directory Structure
- **`Median_Filter/`**: Contains all source files and simulation files for this filter.
  - `main.c`: Source code for the Median Filter.
  - `README.md`: Project-specific details.

### Proteus Lab

#### Overview
The **Proteus Lab** folder includes circuit simulation files developed using Proteus software. These simulations are designed to test and validate various control and filtering methods applied in the lab. Each simulation demonstrates practical applications of the filters and control systems implemented in the course projects.

#### Directory Structure
- **`Proteus-Lab/`**: Contains Proteus simulation files and additional resources for various control experiments.