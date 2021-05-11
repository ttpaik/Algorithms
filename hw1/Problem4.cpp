#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

	ifstream p4;
	char* fn;
	fn = argv[1];
	p4.open(fn);

	if(p4.fail()) {
		cout << "";
		return 1;
	}

	int length = 0;
	string fline, lline;

	if(p4.is_open()) {
		while(getline(p4, fline)) {
			if (fline.length() > length) {
				length = fline.length();
				lline = fline;
			}
		}
		p4.close();
		cout << lline << endl;
	}
	else
		cout << "";
		return 0;
}