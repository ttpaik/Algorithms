#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


int max(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else
		return num2;
}
int min(int num1, int num2)
{
	if (num1 < num2)
	{
		return num1;
	}
	else
		return num2;
}


int main() {
	string fname = "input.txt";
	string line;
	vector<string> vec;
	vector<int> vec2;
	ifstream input;
	input.open(fname);


	while (!input.eof()) {
		input >> line;
		vec.push_back(line);

	}
	vec.push_back("end");

	for (int i = 0; vec[i] != "end"; i++) {
		int num = atoi(vec[i].c_str());
		vec2.push_back(num);


	}

	int lmin = 1, lmax = 1;
	int maxproduct = 0, count = 0, ind = 0, count2 = 0;
	vector<int> pvec;
	for (int j = 0; vec2[j] != '\0'; ++j) {
		if (vec2[j] > 0)
		{
			lmax = lmax * vec2[j];
			lmin = min(lmin * vec2[j], 1);
		}
		else if (vec2[j] == 0)
		{
			lmax = 1;
			lmin = 1;
		}
		else
		{
			int t = lmax;
			lmax = max(lmin * vec2[j], 1);
			lmin = t * vec2[j];
		}


		if (lmax > maxproduct)
		{
			maxproduct = lmax;
		}



		if (vec2[j - 1] == -999999 && vec2[j + 1] == -999999) {
			maxproduct = vec2[j];
			pvec.push_back(maxproduct);
			count++;
			maxproduct = 0;
			lmin = 1, lmax = 1;
			j++;
		}

		else if (vec2[j + 1] == -999999) {

			pvec.push_back(maxproduct);
			count++;
			maxproduct = 0;
			lmin = 1, lmax = 1;
			j++;
		}

	}

	for (int i = 0; i < count; i++)
		cout << pvec[i] << endl;

	int fmax;

	for (int i = 1; i < count; i++) {
		if (pvec[count-(i+1)] < pvec[count - i]) {
			fmax = pvec[count - i];
		}
		else if (pvec[count-(i+1)] > pvec[count - i]) {
			fmax = pvec[count-(i+1)];
		}
	}
	cout << "Max is : " << fmax;
	


	input.close();

	return 0;
}

