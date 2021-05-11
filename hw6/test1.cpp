#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
#include <fstream>
#include <iterator>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

int fourA() {
    int count = 0;
    ifstream partA("BigData.txt");
    string line;
    while (getline(partA, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == 'U') {
                if (isdigit(line[i + 1]) && isdigit(line[i + 2]) && isdigit(line[i + 3]) && isdigit(line[i + 4]) && isdigit(line[i + 5]) && isdigit(line[i + 6]) && isdigit(line[i + 7]) && isdigit(line[i + 8]) && isdigit(line[i + 9]) == 0) {
                    int x;
                    int id_sum = 0;
                    for (int j = 1; j < 9; j++) {
                        x = line[i + j] - '0';
                        id_sum = id_sum + x;
                    }
                    if (id_sum >= 31 && id_sum <= 68)
                        count++;
                }
            }
        }
    }
    partA.close();
    return count;
}

int fourB() {
    ifstream partB("BigData.txt");
    string line;
    int count1 = 0;
    int count2 = 0;
    while (getline(partB, line)) {
        if (line[0] != 'J' && line[0] != 'j')
            count1++;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ' ' || ispunct(line[i]) || isdigit(line[i])) {
                if (isalpha(line[i + 1])) {
                    if (line[i + 1] != 'J' && line[i + 1] != 'j')
                        count2++;
                }
            }
        }
    }
    partB.close();
    int count_sum = count1 + count2;
    return count_sum;
}

void fourC() {
    ifstream partC("Dictionary.txt");
    string per;
    char c;
    partC >> noskipws;
    while (partC >> c) per += c;
    partC.close();
    int s1, s2, longest = 1, point = 0;
    int len = per.length();
    for (int i = 1; i < len; i++) {
        s1 = i - 1;
        s2 = i;
        while (s2 < len && s1 >= 0 && per[s1] == per[s2]) {
            if (s2 - s1 + 1 > longest) {
                longest = s2 - s1 + 1;
                point = s1;
            }
            s1--;
            s2++;
        }
        s1 = i - 1;
        s2 = i + 1;
        while (s2 < len && s1 >= 0 && per[s1] == per[s2]) {
            if (s2 - s1 + 1 > longest) {
                longest = s2 - s1 + 1;
                point = s1;
            }
            s1--;
            s2++;
        }
    }
    int end = point + longest - 1;
    for (int i = point; i <= end; i++)
        cout << per[i];
}

int main() {
    int result_A = fourA();
    cout << result_A << endl;
    int result_B = fourB();
    cout << result_B << endl;
    fourC();
    return 0;
}