#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

#include "../TimePerformance/dominolinebuilder.h"
#include "../../dominoes/dominolinebuilder.h"

using namespace std;
using namespace std::chrono;
using std::chrono::steady_clock;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

nanoseconds dominoTimingPerformance(unsigned long long int totalNumberOfDominoes, unsigned long long int numberOfLookups)
{
	steady_clock::time_point startTime = steady_clock::now();

	steady_clock::time_point finishTime = steady_clock::now();

	nanoseconds timeTaken = duration_cast<nanoseconds>(finishTime - startTime);

	nanoseconds meanTimePerLookup = timeTaken / totalNumberOfDominoes;

	return meanTimePerLookup;
}

int main()
{
	const unsigned long int totalNumberOfDominoes = 1000;
	const std::string filepath = "C:/Users/Joe Blackbourn/source/repos/dominoes/dominoes-test_data/300/300-input.txt";

	std::ifstream theInputStream(filepath);
	if (!theInputStream.good()) throw std::invalid_argument("Cannot read from specified file.");

	const unsigned long int numberOfLookups = 245;

	nanoseconds meanTimePerLookup = dominoTimingPerformance(totalNumberOfDominoes, numberOfLookups);

	std::cout << "The number of dominoes" << totalNumberOfDominoes << "inserted" << std::endl;
	std::cout << "Performing" << numberOfLookups << "lookups" << std::endl;
	std::cout << "Mean time taken per lookup: " << meanTimePerLookup.count() << std::endl;


}


