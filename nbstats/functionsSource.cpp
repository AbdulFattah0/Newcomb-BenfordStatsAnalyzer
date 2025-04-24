/*
* Abdul Fatiah Marouf
* March, 09, 2024
* Source File to include all the functions bodies to use them in the main source file
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <sstream>

#include "functions.hpp"



using namespace std;


/*
  * Method Name: calculateRange();
  * Purpose: Prints the range of a vector of doubles by sorting and displaying the smallest and largest numbers.
  * Accepts: vector<double>& numbers .
  * Returns: void - Outputs the range directly.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
void calculateRange(vector<double>& numbers) {
	sort(numbers.begin(), numbers.end());
	cout << "[ " << numbers.front() << " ... " << numbers.back() << "]";
}


/*
  * Method Name: calculateMean();
  * Purpose: Calculates and returns the arithmetic mean  of a vector of doubles.
  * Accepts: const vector<double>& numbers.
  * Returns: double - The calculated mean of the input numbers.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateMean(const vector<double>& numbers)
{
	double sum = 0.0;
	for (double num : numbers) {
		sum += num;
	}
	return sum / numbers.size();
}


/*
  * Method Name: calculateMedian();
  * Purpose: Calculates and returns the median of a vector of doubles.
  * Accepts: vector<double> numbers -
  * Returns: double - The median of the input numbers.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateMedian(vector<double> numbers)
{
	size_t size = numbers.size();
	sort(numbers.begin(), numbers.end());

	if (size % 2 == 0)
	{
		return(numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
	}
	else {
		return numbers[size / 2];
	}
}


/*
  * Method Name: calculateVariance();
  * Purpose: Computes the variance of a given vector of doubles, indicating how spread out the numbers are from their mean.
  * Accepts: const vector<double>& numbers
  * Returns: double - The variance of the input numbers.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateVariance(const vector<double>& numbers)
{
	double sum = 0.0;
	for (double num : numbers) {
		sum += num;
	}

	double mean = sum / numbers.size();

	double sumSquares = 0.0;
	for (double num : numbers)
	{
		sumSquares += (num - mean) * (num - mean);
	}
	return sumSquares / numbers.size();
}


/*
  * Method Name: calculateStandardDeviation();
  * Purpose: Calculates the standard deviation from the given variance.
  * Accepts: double variance - The variance of a set of numbers.
  * Returns: double - The standard deviation calculated from the variance.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateStandardDeviation(double variance) {
	return sqrt(variance);
}


/*
  * Method Name: calculateMode();
  * Purpose: Identifies the mode in a vector of doubles If all numbers are unique, the modes vector is cleared, indicating no mode.
  * Accepts:
  * - const vector<double>& numbers - The dataset to find the mode of.
  * - vector<double>& modes - A reference to a vector where the mode will be stored.
  * Returns: void - Modifies the 'mode' vector directly with the result.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
void calculateMode(const vector<double>& numbers, vector<double>& modes) {
	unordered_map<double, int> frequencyMap;
	int maxFrequency = 0;

	// Calculate frequencies
	for (double num : numbers) {
		maxFrequency = max(maxFrequency, ++frequencyMap[num]);
	}

	// Find all numbers with the maximum frequency
	for (const auto& pair : frequencyMap) {
		if (pair.second == maxFrequency) {
			modes.push_back(pair.first);
		}
	}

	// If all numbers occur with the same frequency , clear the modes vector
	if (modes.size() == frequencyMap.size()) {
		modes.clear();
	}
}


/*
  * Method Name: log10NewcombBenford
  * Purpose: Calculates the logarithm (base 10) expected by Newcomb-Benford's Law for a given digit.
  * Accepts: int digit - The digit (1 through 9) to calculate the expected logarithmic distribution for.
  * Returns: double - The base 10 logarithm of (1 + 1/digit), as per Newcomb-Benford's Law.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double log10NewcombBenford(int digit) {
	return log10(1.0 + 1.0 / digit);
}


/*
  * Method Name: calculateNBVariance();
  * Purpose: Calculates the variance from expected proportions in Newcomb-Benford's Law across a set of digits.
  * Accepts:
  * - const unordered_map<int, int>& frequencyTable: Map of digit frequencies.
  * - double totalNumbers: Total count of numbers analyzed.
  * Returns: double - The calculated variance according to Newcomb-Benford's Law.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateNBVariance(const unordered_map<int, int>& frequencyTable, double totalNumbers) {
	if (totalNumbers == 0) return 0.0;

	double nbVariance = 0.0;
	// Iterate through the digits 1 to 9
	for (int i = 1; i <= 9; ++i) {
		// Calculate expected proportion for each digit
		double expectedProportion = log10(1.0 + 1.0 / i);

		double actualFrequency = 0.0;

		// Find the digit in the frequency table
		auto it = frequencyTable.find(i);
		if (it != frequencyTable.end()) {

			// Update actual frequency if digit is found
			actualFrequency = static_cast<double>(it->second);
		}

		if (expectedProportion != 0) {
			// Calculate the squared difference ratio for the digit and add it to the variance sum
			nbVariance += pow((actualFrequency / totalNumbers) / expectedProportion - 1, 2);
		}
	}

	nbVariance /= 9;

	return nbVariance;
}


/*
  * Method Name: nbRelationshipAnalysis();
  * Purpose: Analyzes and categorizes the strength of the Newcomb-Benford deviation into descriptive terms.
  * Accepts: double nbDeviation - The calculated Newcomb-Benford deviation.
  * Returns: string - A descriptive term categorizing the strength of the relationship.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
string nbRelationshipAnalysis(double nbDeviation) {
	if (nbDeviation < 0.1) return "very strong";
	if (nbDeviation < 0.2) return "strong";
	if (nbDeviation < 0.35) return "moderate";
	if (nbDeviation < 0.5) return "weak";
	return "no";
}


/*
  * Method Name: calculateNBStandardDeviation();
  * Purpose: Calculates the standard deviation for Newcomb-Benford variance.
  * Accepts: double variance - The variance calculated based on Newcomb-Benford's.
  * Returns: double - The standard deviation derived from the Newcomb-Benford variance.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateNBStandardDeviation(double variance) {
	return sqrt(variance);
}


/*
  * Method Name: printBarGraph();
  * Purpose: Prints a simple bar graph representation using '#' characters.
  * Accepts: double percentage - The percentage value to be represented in the bar graph.
  * Returns: void - Outputs the graphical representation directly to the standard output.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
void printBarGraph(double percentage) {
	int length = static_cast<int>(percentage / 2.5);
	for (int i = 0; i < length; i++) {
		cout << "#";
	}
}


/*
  * Method Name: getFirstDigit();
  * Purpose: Extracts and returns the first (most significant) digit of a given positive number.
  * Accepts: double number - The number from which the first digit will be extracted.
  * Returns: size_t - The first digit of the given number.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
size_t getFirstDigit(double number) {
	int digit = static_cast<int>(number);
	while (digit >= 10) digit /= 10;
	return digit;
}


/*
  * Method Name: calculateFrequencyTable();
  * Purpose: Populates a frequency table with the counts of the first digits of numbers in a vector.
  * Accepts:
  * - const vector<double>& numbers: A vector of numbers from which to calculate the frequency of first digits.
  * - unordered_map<int, int>& frequencyTable: A reference to a map where the key is the first digit (1-9) and the value is the frequency of that digit.
  * Returns: void - Directly modifies the frequencyTable map with counts of first digits.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
void calculateFrequencyTable(const vector<double>& numbers, unordered_map<int, int>& frequencyTable) {
	for (double num : numbers) {
		int firstDigit = static_cast<int>(getFirstDigit(num));
		frequencyTable[firstDigit]++;
	}
}


/*
  * Method Name: load_data
  * Purpose: Reads and parses double values from an input stream, optionally skipping invalid or negative inputs, and stores them in a vector.
  * Accepts:
  * - istream& stream: The input stream to read data from. Can be from a file, cin, or any other input stream.
  * - vector<double>& v: A reference to a vector where valid parsed numbers are stored.
  * - bool skipBad: A flag indicating whether to skip over invalid inputs without terminating the function.
  * Returns: void - The function does not return a value but modifies the vector 'v' directly with the parsed numbers.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
void load_data(istream& stream, vector<double>& v, bool skipBad) {
	string line;
	double value;

	while (getline(stream, line)) {
		// Check if line is empty, which may indicate EOF if ^Z is used in some environments
		if (line.empty()) break;

		// Create a stringstream from the line for easier parsing
		stringstream ss(line);
		string input;

		while (ss >> input) {
			try {
				value = stod(input);
				if (value > 0) { // Assuming you still only want positive values
					v.push_back(value);
				}
			}
			catch (const invalid_argument&) {
				if (!skipBad) {
					cerr << "Error: invalid input <" << input << "> rejected" << endl;
					return; // Exit the function or handle as needed
				}
				else {
					cerr << "Warning: invalid input <" << input << "> rejected" << endl;
				}
			}
			catch (const out_of_range&) {
				cerr << "Warning: input out of range <" << input << "> rejected" << endl;
			}
		}

		// Check for immediate EOF after line read (specific to handling ^Z inline)
		if (stream.eof()) break;
	}
}

