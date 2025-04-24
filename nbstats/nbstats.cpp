/*
* Abdul Fatiah Marouf
* Student  Num : 1144451
* March, 09, 2024
* The program analyzes real number datasets, calculating statistics like mean, median, and mode, and evaluates their
* conformity to Newcomb-Benford's Law. It accepts data from a file or user input, offering options for help, version info,
* and handling invalid inputs.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <string>
#include <fstream>
#include "functions.hpp"


using namespace std;


int main(int argc, char* argv[]) {
    bool help = false, version = false, skipBad = false;
    string filename;

    // Process command-line arguments
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "--help") help = true;
        else if (arg == "--version") version = true;
        else if (arg == "--skipbad") skipBad = true;
        else filename = arg;
    }

    // Print help message
    if (help) {
        cout << "Usage: " << endl;
        cout << "stats [--(help|skipbad|version)]* [filename]" << endl;
        cout << endl;
        cout << "      --help      display instructions." << endl;
        cout << "      --version   Show version number." << endl;
        cout << "      --skipbad   Skip bad input values." << endl;
        return 0;
    }

    // Print version info
    if (version) {
        cout << "stats (2024.03.09), Abdul Fattah" << endl;
        return 0;
    }

    vector<double> numbers;

    // Attempt to open file if filename is provided, else read from standard input
    ifstream infile;
    if (!filename.empty()) {
        infile.open(filename);
        if (!infile) {
            cerr << "Error: File not found." << endl;
            return EXIT_FAILURE;
        }
        load_data(infile, numbers, skipBad);
    }
    else {
        cout << "stats (2024.03.09), 2024 Abdul" << endl;
        cout << "=============================================" << endl;
        cout << "Enter whitespace-separated real numbers. Terminate input with ^Z" << endl;
        load_data(cin, numbers, skipBad);
    }

    if (numbers.empty()) {
        cout << "No valid numbers provided." << endl;
        return 0;
    }

    unordered_map<int, int> frequencyTable;



    // Calculating statistics
    calculateFrequencyTable(numbers, frequencyTable);
    cout << endl;
    cout << "Standard Analysis" << endl;
    cout << "==============================================================" << endl;
    cout << endl;
    cout << "# elements   = " << numbers.size() << endl;
    cout << "Range = ";
    calculateRange(numbers);
    cout << "\nArithmetic mean   = " << calculateMean(numbers);
    cout << "\nArithmetic median = " << calculateMedian(numbers);
    double variance = calculateVariance(numbers);
    cout << "\nVariance = " << variance;
    cout << "\nStandard Deviation = " << calculateStandardDeviation(variance);
    vector<double> modes;
    calculateMode(numbers, modes);
    cout << "\n\nMode = ";
    if (modes.empty() || modes.size() > 1) {
        cout << "no mode";
    }
    else {
        for (double mode : modes) {
            cout << mode << " ";
        }
    }
    cout << "\n\n";

    // Newcomb-Benford Analysis
    double  nbVariance = calculateNBVariance(frequencyTable, numbers.size());
    double nbStdDev = calculateNBStandardDeviation(nbVariance);
    string nbRelationship = nbRelationshipAnalysis(nbStdDev);

    cout << "Newcomb-Benford's Law Analysis" << endl;
    cout << "===============================================================" << endl;
    cout << "    exp digit    freq 0  10  20  30  40  50  60  70  80  90 100" << endl;
    cout << "--------------------- +---+---+---+---+---+---+---+---+---+---+" << endl;
    for (int i = 1; i <= 9; ++i) {
        double expected = log10NewcombBenford(i) * 100;
        // Calculate actual frequency percentage
        double actual = (frequencyTable.find(i) != frequencyTable.end()) ? static_cast<double>(frequencyTable.at(i)) / numbers.size() * 100 : 0;

        cout << fixed << setprecision(2)
            << setw(6) << expected << "% [" << i << "] = "
            << setw(6) << actual << "% |";
        printBarGraph(actual);
        cout << endl;
    }
    cout << "--------------------  +---+---+---+---+---+---+---+---+---+---+" << endl;
    cout << "Variance  = " << fixed << setprecision(5) << nbVariance * 100 << "%" << endl;
    cout << "Std. Dev. = " << fixed << setprecision(5) << nbStdDev * 100 << "%" << endl;
    cout << "There is " << nbRelationship << " Benford relationship." << endl;
    cout << "===============================================================" << endl;

    
}
