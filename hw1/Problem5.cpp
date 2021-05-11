#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int steps(int n) {
	if (n == 1 || n == 0) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n > 2) {
		return steps(n-3) + steps(n-2) + steps(n-1);
	}
}

int main(int argc, char **argv) {
	
	char* sol = argv[1];
	int num = atoi(sol);

	cout << steps(num) << endl;
	return 0;
}
