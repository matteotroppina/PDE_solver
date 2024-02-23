# Performance Analysis and Optimization Report

This document outlines the performance analysis on the Jacobi test for the 2D Poisson equation solver, using default parameters specified in `test.csv`. The analysis includes initial benchmarking, profiling with `gprof`, and subsequent optimization strategies applied to enhance performance.

An initial benchmarking memory bandwidth with STREAM provides an insight into the memory bandwidth capabilities of the hardware utilized for the performance analysis:

| Function | Best Rate MB/s | Avg time | Min time | Max time |
| -------- | -------------- | -------- | -------- | -------- |
| Copy     | 23498.3        | 0.007372 | 0.006809 | 0.009033 |
| Scale    | 23286.3        | 0.007183 | 0.006871 | 0.007961 |
| Add      | 27881.5        | 0.009217 | 0.008608 | 0.011332 |
| Triad    | 28027.4        | 0.008923 | 0.008563 | 0.009630 |

## Profiling (no optimization)

Profiling the application with `gprof` highlighted several hotspots:

| % Time | Cumulative Seconds | Self Seconds | Calls       | s/call | s/call Total | Function                          |
| ------ | ------------------ | ------------ | ----------- | ------ | ------------ | --------------------------------- |
| 11.68% | 0.35               | 0.35         | 374,740,052 | 0.00   | 0.00         | `std::vector::at`                 |
| 11.51% | 0.70               | 0.35         | 549,685,071 | 0.00   | 0.00         | `std::vector::_M_range_check`     |
| 9.21%  | 0.98               | 0.28         | 549,695,069 | 0.00   | 0.00         | `std::vector::size`               |
| 8.72%  | 1.25               | 0.27         | 549,685,071 | 0.00   | 0.00         | `std::vector::at`                 |
| 6.25%  | 1.44               | 0.19         | 374,740,052 | 0.00   | 0.00         | `std::vector::_M_range_check`     |
| 6.25%  | 1.63               | 0.19         | 1           | 0.19   | 3.01         | `testJacobi`                      |
| 5.10%  | 1.78               | 0.15         | 599,710,067 | 0.00   | 0.00         | `std::vector::size`               |
| 4.28%  | 1.92               | 0.13         | 274,800,040 | 0.00   | 0.00         | `Mesh::getNode`                   |
| 3.95%  | 2.04               | 0.12         | 549,685,071 | 0.00   | 0.00         | `std::vector::operator[]`         |
| 3.95%  | 2.15               | 0.12         | 1           | 0.12   | 0.86         | `Boundaries::setInnerNodes`       |
| 3.62%  | 2.27               | 0.11         | 2           | 0.06   | 0.18         | `std::vector::_M_fill_initialize` |
| 3.29%  | 2.37               | 0.10         | 374,740,052 | 0.00   | 0.00         | `std::vector::operator[]`         |
| 3.29%  | 2.46               | 0.10         | 1           | 0.10   | 1.15         | `jacobi`                          |
| 2.47%  | 2.54               | 0.07         | 1           | 0.07   | 0.35         | `Mesh::swapGrids`                 |
| 2.30%  | 2.61               | 0.07         | 10,000      | 0.00   | 0.00         | `Node* std::__uninitialized_copy` |
| 2.14%  | 2.67               | 0.07         | 174,945,017 | 0.00   | 0.00         | `Mesh::numCols`                   |

Total Runtime: 3.52s

- Frequent calls to `std::vector::at(unsigned long)`.
- Frequent calls to `Mesh::numCols()` and `Mesh::numCols()` that leads to excessive use of `std::size()`.
- Poorly implemented `Mesh::swapGrids()`.

To profile your application, execute:

    ./src/PDEsolver --test
    gprof ./src/PDEsolver gmon.out > analysis.txt

The profiling output is available in `analysis.txt` within the build directory.

## Optimization Strategies

### Optimizing Frequent `std::vector::size()` Calls

- **Issue**: Repeated calls to `std::vector::size()` within loops.
- **Solution**: Cached the size of vectors before entering loops to avoid repeated function calls.

  After optimization:

  - Total Runtime: 2.24s
  - Runtime optimization: 36%

### Reducing `std::vector::at()` Calls

- **Issue**: A significant amount of time was spent on bounds-checked access via `std::vector::at()`.
- **Solution**: Replaced `std::vector::at()` with `operator[]` for direct access, after ensuring index bounds are checked ahead of time.

  After optimization:

  - Total Runtime: 1.28s
  - Runtime optimization: 27%

### Optimizing `Mesh::swapGrids()`

- **Issue**: The function swaps the grid entries one by one, inefficient use of `std::swap`.
- **Solution**: Efficient use of `std::swap`.

  After oprimization:

  - Total Runtime: 1.12s
  - Runtime optimization: 5%

## Profiling after optimization

| % Time | Cumulative Seconds | Self Seconds | Calls       | s/call | s/call Total | Function                                   |
| ------ | ------------------ | ------------ | ----------- | ------ | ------------ | ------------------------------------------ |
| 19.57% | 0.23s              | 0.23s        | 274,800,040 | 0.00s  | 0.00s        | `Mesh::getNode`                            |
| 13.91% | 0.39s              | 0.16s        | 324,780,050 | 0.00s  | 0.00s        | `std::vector::operator[]`                  |
| 11.74% | 0.52s              | 0.14s        | 324,780,044 | 0.00s  | 0.00s        | `std::vector::operator[]`                  |
| 10.00% | 0.64s              | 0.12s        | 50,000,000  | 0.00s  | 0.00s        | `std::_Construct`                          |
| 8.70%  | 0.73s              | 0.10s        | 1           | 0.10s  | 0.35s        | `Boundaries::setInnerNodes`                |
| 6.09%  | 0.81s              | 0.07s        | 10,000      | 0.00s  | 0.00s        | `std::__uninitialized_copy`                |
| 5.65%  | 0.87s              | 0.07s        | 2           | 0.03s  | 0.17s        | `std::vector::vector`                      |
| 4.78%  | 0.93s              | 0.06s        | 25,000,000  | 0.00s  | 0.00s        | `Mesh::setNode`                            |
| 4.35%  | 0.97s              | 0.05s        | 50,010,000  | 0.00s  | 0.00s        | `__gnu_cxx::operator!=`                    |
| 4.35%  | 1.02s              | 0.05s        | 1           | 0.05s  | 0.29s        | `jacobi`                                   |
| 2.61%  | 1.05s              | 0.03s        | 1           | 0.03s  | 0.07s        | `printToCSV`                               |
| 2.61%  | 1.08s              | 0.03s        | 1           | 0.03s  | 0.38s        | `Mesh::Mesh`                               |
| 1.74%  | 1.10s              | 0.02s        | 100,020,004 | 0.00s  | 0.00s        | `__gnu_cxx::__normal_iterator::base`       |
| 1.74%  | 1.12s              | 0.02s        | 50,000,000  | 0.00s  | 0.00s        | `__gnu_cxx::__normal_iterator::operator++` |

- Total Runtime: 1.12s

- Total Runtime Optimization: 68%

## Compiler optimizations

- **Optimization Level**: `-O2`
- **Impact on Runtime**: Reduced runtime from 1.12 seconds to 1.02 seconds.
- Runtime Optimization: 3%

The `-O2` optimization level enables loop optimizations, function inlining, and other improvements.
While the `-O2` optimization did lead to a runtime improvement, it was not as substantial as expected. To achieve more significant improvements, a more cache friendly way to get the data from the grid or a more efficient way to trigger loop unrolling by the compiler can be implemented.
