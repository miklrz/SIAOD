#include <iostream>
#include <math.h>
using namespace std;

bool is_prime(int n) {
	for (int i = 2; i < int(sqrt(n) + 1); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

