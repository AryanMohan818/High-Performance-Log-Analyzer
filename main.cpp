#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <chrono> // To measure speed

using namespace std;

int main() {
    cout << "🚀 STARTING HIGH-PERFORMANCE LOG ANALYSIS..." << endl;

    // 1. Start the Timer (To prove speed on your resume)
    auto start = chrono::high_resolution_clock::now();

    ifstream file("server_logs.txt");
    if (!file.is_open()) {
        cerr << "❌ Error: Could not open file!" << endl;
        return 1;
    }

    string line;
    map<string, int> stats;
    long long total_lines = 0;

    // 2. The "Fast Read" Loop
    // We parse millions of lines here
    while (getline(file, line)) {
        total_lines++;
        
        // Simple manual parsing (Faster than Regex for this case)
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

    // 3. Stop Timer
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // 4. Report
    cout << "--------------------------------------" << endl;
    cout << "📊 ANALYSIS REPORT" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Total Lines Processed: " << total_lines << endl;
    cout << "🔴 Critical Errors:    " << stats["CRITICAL"] << endl;
    cout << "🟠 Standard Errors:    " << stats["ERROR"] << endl;
    cout << "🟡 Warnings:           " << stats["WARNING"] << endl;
    cout << "--------------------------------------" << endl;
    cout << "⚡ Time Taken: " << duration.count() << " seconds" << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}