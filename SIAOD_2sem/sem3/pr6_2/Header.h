#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;

//1
bool isValidWord(const std::string& word);
std::string findLongestWord(const std::string& sentence);

//2
std::vector<int> computePrefixFunction(const std::string& pattern);
int findLastOccurrence(const std::string& text, const std::string& pattern);