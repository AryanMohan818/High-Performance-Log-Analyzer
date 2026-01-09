# High-Throughput Log Analysis Engine ⚡

A high-performance C++ log auditing tool engineered to process massive server logs with minimal latency. Capable of parsing and analyzing **1 Million+ log entries in ~1.1 seconds**.

## 🚀 Overview
In distributed systems, server logs grow exponentially. Standard parsing tools often fail to keep up with the volume. This project implements a custom-built analysis engine that prioritizes **I/O throughput** and **memory efficiency**.

It reads raw log files, filters for critical errors (WARN/ERROR), and generates statistical reports, serving as a prototype for automated system health monitoring in high-frequency trading environments.

## ⚡ Performance Benchmarks
| Metric | Result |
| :--- | :--- |
| **Dataset Size** | 1,000,000+ Lines |
| **Execution Time** | **1.12 Seconds** |
| **Throughput** | ~900k lines/sec |
| **Complexity** | O(N) Linear Time |

## 🛠️ Key Optimizations
* **Custom I/O Buffering:** Implemented a **128KB custom buffer** for file streams to minimize expensive disk seek operations and context switching.
* **Compiler Optimization:** Tuned for **GCC -O3** (Level 3 Optimization) to enable loop unrolling and vectorization.
* **Memory Management:** utilized `std::vector` with `reserve()` to prevent costly memory reallocations during runtime.
* **Fast String Handling:** Avoided heavy regex in favor of optimized string parsing to reduce CPU cycles per line.

## 💻 Technical Stack
* **Language:** C++ (Standard Template Library)
* **Compiler:** GCC / MinGW
* **Concepts:** File I/O, Buffer Tuning, Algorithm Optimization

## ⚙️ Build & Run Instructions

1. **Clone the repository**
   ```bash
   git clone [https://github.com/AryanMohan818/High-Performance-Log-Analyzer.git](https://github.com/AryanMohan818/High-Performance-Log-Analyzer.git)
   cd High-Performance-Log-Analyzer
2. **Compile with Optimization**
   Note: The -O3 flag is crucial for achieving sub-1.2s performance.
   **Bash Command** = g++ -O3 main.cpp -o log_parser
3. **Run the Analizer**
   **Bash Command** = ./log_parser

📊 Sample Output
[INFO] Processing Log File...
[SUCCESS] Processing Complete.
----------------------------------
Total Lines Processed: 1,000,000
Errors Found: 5,420
Warnings Found: 12,300
Time Taken: 1.12287 seconds
----------------------------------
### 💡 **Why this wins**:
1.  **The Table:** Recruiters scan fast. A table showing **"1.12 Seconds"** proves you measured your code.
2.  **"O(N) Linear Time":** This connects your project directly to your Data Structures & Algorithms coursework.
3.  **"Loop Unrolling & Vectorization":** These are specific terms related to the `-O3` flag. Mentioning them shows you know *what* the compiler is doing, not just that you blindly typed a command.

**Shall we knock out the last one (The Flutter Dashboard) so your portfolio is 100% complete?**

