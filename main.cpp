#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <chrono> 

using namespace std;

// Optimization: Use a larger buffer for file reading to reduce disk I/O
const int BUFFER_SIZE = 128 * 1024; // 128KB buffer

int main() {
    cout << "🚀 STARTING HIGH-PERFORMANCE LOG ANALYSIS..." << endl;

    auto start = chrono::high_resolution_clock::now();

    ifstream file("server_logs.txt");
    if (!file.is_open()) {
        cerr << "❌ Error: Could not open file!" << endl;
        return 1;
    }

    // Optimization: Set a manual buffer for the file stream
    char buffer[BUFFER_SIZE];
    file.rdbuf()->pubsetbuf(buffer, BUFFER_SIZE);

    string line;
    map<string, int> stats;
    long long total_lines = 0;

    // Fast Read Loop
    while (getline(file, line)) {
        total_lines++;
        
        // Manual optimization: Check the most common cases first
        if (line.find("| ERROR |") != string::npos) {
            stats["ERROR"]++;
        } 
        else if (line.find("| CRITICAL |") != string::npos) {
            stats["CRITICAL"]++;
        }
        else if (line.find("| WARNING |") != string::npos) {
            stats["WARNING"]++;
        }
    }

    file.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "--------------------------------------" << endl;
    cout << "📊 ANALYSIS REPORT" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Total Lines:        " << total_lines << endl;
    cout << "🔴 Critical Errors: " << stats["CRITICAL"] << endl;
    cout << "⚡ Time Taken:      " << duration.count() << " seconds" << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}