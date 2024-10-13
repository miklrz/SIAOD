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
#include <algorithm> // Для std::sort
using namespace std;

struct PhoneNumberOwner {
	string phoneNumber; // ключ
	string address;
};

struct IndexEntry {
	string phoneNumber;
	streampos offset;

	// Оператор сравнения для сортировки
	bool operator<(const IndexEntry& other) const {
		return phoneNumber < other.phoneNumber;
	}
};

void createTextFile(const string& filename, int len);
void createBinaryFile(const string& textFilename, const string& binaryFilename, vector<IndexEntry>& index_table);
PhoneNumberOwner linearSearch(const string& binaryFilename, string phoneNumberKey);
string getRandomPhoneNumber(const string& binaryFilename, int fileLen);

streampos binarySearch(const vector<IndexEntry>& indexTable, const string& key);
PhoneNumberOwner readPhoneOwner(const string& binaryFilename, streampos offset);