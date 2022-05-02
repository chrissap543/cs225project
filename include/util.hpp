#include <string>
#include <vector>
#include <sstream>

/**
 * @brief Takes a line and splits by comma (note: removes first column)
 * @param line a string to be split
 * @return a vector of the subcomponents
 * Splits the line into their comma-separated values. 
 * Note that this will delete the first entry of the line since
 * our data uses indices as the first column (which we are ignoring). 
 */
std::vector<std::string> splitLine(std::string line); 

/**
 * Helper functions to trim whitespace inplace
 * Used in splitLine to ensure no whitespace in csv file
 * If there was whitespace, could cause extra nodes to be created
 */
static void trim(std::string& str); 
static void trimLeft(std::string& str); 
static void trimRight(std::string& str); 