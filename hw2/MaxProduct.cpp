#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include "MaxProduct.h"

using namespace std;

// Name : Taehyon Paik     ID : U58182574

int MaxProductClass::MaxProduct(string file) {
	
	ifstream input;
	input.open(file);
	


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
	int maxproduct = 0, count = 0;
	for (int j = 0; vec2[j] != '\0'; ++j) {
		
		if (vec2[j] > 0)
		{
			lmax = lmax * vec2[j];
			lmin = min(lmin * vec2[j], 1);
		}

		else if (vec2[j] == 0)
		{
			lmax = 1; lmin = 1;
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

		/*else if (vec2[j + 1] == 0) {
			pvec.push_back(maxproduct);
			j++;
			count++;
			lmin = 1, lmax = 1;
			maxproduct = 0;
		}*/

	}

	for (int i = 0; i < count; i++)
		cout << pvec[i] << endl;

	int fmax1, fmax = 0;

	for (int i = 1; i < count; i++) {
		fmax1 = max(pvec[i], pvec[i + 1]);
		if (fmax1 > fmax) {
			fmax = fmax1;
		}
		else if (fmax1 <= fmax) {
			fmax = fmax;
		}
	}
	input.close();

	return fmax;
}


int MaxProductClass::max(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else
		return num2;
}

int MaxProductClass::min(int num1, int num2)
{
	if (num1 < num2)
	{
		return num1;
	}
	else
		return num2;
}








/*for (int j = 0; vec2[j] != '\0'; ++j) {
		if (vec2[j] == 0)
		{
			lmax = 1;
			lmin = 1;
		}
		else if (vec2[j] > 0)
		{
			lmax = lmax * vec2[j];
			lmin = min(lmin * vec2[j], 1);
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

		if (vec2[j] != -999999) {
			int x = (vec2[j]) * (vec2[j + 2]);
			int y = (vec2[j]) * (vec2[j + 1]) * (vec2[j + 2]);
			int z = max(x, y);
			pvec.push_back(z);
			j++; count++;
			lmin = 1, lmax = 1;
		}

		else if (vec2[j - 1] == -999999 && vec2[j + 1] == -999999) {
			maxproduct = vec2[j];
			pvec.push_back(maxproduct);
			count++;
			maxproduct = 0;
			lmin = 1, lmax = 1;
			j++;
		}

		else if (vec2[j + 2] == -999999) {
			pvec.push_back(maxproduct);
			count++;
			maxproduct = 0;
			lmin = 1, lmax = 1;
			j++;
		}

		else if (vec2[j] == 0) {
			pvec.push_back(maxproduct);
			j++;
			count++;
			lmin = 1, lmax = 1;
		}
	}*/