#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <cstdlib> 
#include <ctime>    
#include <chrono>
#include <vector>
using namespace std;

struct PhoneNumberOwner {
	string phoneNumber; // ключ
	string address;
};

void createTextFile(const string& filename, int len);
void createBinaryFile(const string& textFilename, const string& binaryFilename);
PhoneNumberOwner linearSearch(const string& binaryFilename, string phoneNumberKey);
string getRandomPhoneNumber(const string& binaryFilename, int fileLen);
