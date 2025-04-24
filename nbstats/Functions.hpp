/*
* Abdul Fatiah Marouf
* March, 09, 2024
* Header file to declare all the function headers
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
  * Method Name: calculateRange();
  * Purpose: Prints the range of a vector of doubles by sorting and displaying the smallest and largest numbers.
  * Accepts: vector<double>& numbers .
  * Returns: void - Outputs the range directly.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
void calculateRange(vector<double>& numbers);


/*
  * Method Name: calculateMean();
  * Purpose: Calculates and returns the arithmetic mean  of a vector of doubles.
  * Accepts: const vector<double>& numbers.
  * Returns: double - The calculated mean of the input numbers.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateMean(const vector<double>& numbers);

/*
  * Method Name: calculateMedian();
  * Purpose: Calculates and returns the median of a vector of doubles.
  * Accepts: vector<double> numbers -
  * Returns: double - The median of the input numbers.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateMedian(vector<double> numbers);


/*
  * Method Name: calculateVariance();
  * Purpose: Computes the variance of a given vector of doubles, indicating how spread out the numbers are from their mean.
  * Accepts: const vector<double>& numbers
  * Returns: double - The variance of the input numbers.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateVariance(const vector<double>& numbers);


/*
  * Method Name: calculateStandardDeviation();
  * Purpose: Calculates the standard deviation from the given variance.
  * Accepts: double variance - The variance of a set of numbers.
  * Returns: double - The standard deviation calculated from the variance.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateStandardDeviation(double variance);


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
void calculateMode(const vector<double>& numbers, vector<double>& modes);


/*
  * Method Name: log10NewcombBenford
  * Purpose: Calculates the logarithm (base 10) expected by Newcomb-Benford's Law for a given digit.
  * Accepts: int digit - The digit (1 through 9) to calculate the expected logarithmic distribution for.
  * Returns: double - The base 10 logarithm of (1 + 1/digit), as per Newcomb-Benford's Law.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double log10NewcombBenford(int digit);


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
double calculateNBVariance(const unordered_map<int, int>& frequencyTable, double totalNumbers);


/*
  * Method Name: nbRelationshipAnalysis();
  * Purpose: Analyzes and categorizes the strength of the Newcomb-Benford deviation into descriptive terms.
  * Accepts: double nbDeviation - The calculated Newcomb-Benford deviation.
  * Returns: string - A descriptive term categorizing the strength of the relationship.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
string nbRelationshipAnalysis(double nbDeviation);


/*
  * Method Name: calculateNBStandardDeviation();
  * Purpose: Calculates the standard deviation for Newcomb-Benford variance.
  * Accepts: double variance - The variance calculated based on Newcomb-Benford's.
  * Returns: double - The standard deviation derived from the Newcomb-Benford variance.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
double calculateNBStandardDeviation(double variance);


/*
  * Method Name: printBarGraph();
  * Purpose: Prints a simple bar graph representation using '#' characters.
  * Accepts: double percentage - The percentage value to be represented in the bar graph.
  * Returns: void - Outputs the graphical representation directly to the standard output.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
void printBarGraph(double percentage);


/*
  * Method Name: getFirstDigit();
  * Purpose: Extracts and returns the first (most significant) digit of a given positive number.
  * Accepts: double number - The number from which the first digit will be extracted.
  * Returns: size_t - The first digit of the given number.
  * Coder: Abdul Fatiah
  * Date: March, 09, 2024
 */
size_t getFirstDigit(double number);


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
void calculateFrequencyTable(const vector<double>& numbers, unordered_map<int, int>& frequencyTable);


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
void load_data(istream& stream, vector<double>& v, bool skipBad);