#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
using namespace std;


void fourA() {
    int answer1 = 0;
    string data;
    ifstream Q5_a("BigData.txt");
    
    while (getline(Q5_a, data)) {

        for (int i = 0; i < data.length(); i++) {

            if (data[i] == 'U') {

                if (isdigit(data[i + 1]) && isdigit(data[i + 2]) && isdigit(data[i + 3]) && isdigit(data[i + 4]) && isdigit(data[i + 5]) && isdigit(data[i + 6]) && isdigit(data[i + 7]) && isdigit(data[i + 8]) && !isdigit(data[i + 9])) {

                    int num, sum = 0;

                    for (int j = 1; j < 9; j++) {
                        num = data[i + j] - '0';
                        sum = sum + num;
                    }

                    if (sum >= 31 && sum <= 68) {
                        answer1++;
                    }
                }
            }
        }
    }
    Q5_a.close();
    cout << answer1 << endl;
}

void fourB() {
    int answer2_1 = 0;
    int answer2_2 = 0;
    string data_b;
    ifstream Q5_b("BigData.txt");

    while (getline(Q5_b, data_b)) {

        for (int i = 0; i < data_b.length(); i++) {
            
            if (isdigit(data_b[i]) || ispunct(data_b[i]) || data_b[i] == ' ') {

                if (isalpha(data_b[i + 1])) {

                    if (data_b[i + 1] != 't' && data_b[i + 1] != 'T') {
                        answer2_1++;
                    }
                }
            }
        }

        if (data_b[0] != 't' && data_b[0] != 'T') {
            answer2_2++;
        }
    }  

    Q5_b.close();
    cout << answer2_1 + answer2_2 << endl;
}

void fourC() {
    int pali_len = 1;
    int start_p = 0;
    int left, right;
    string answer_pali;
    ifstream Q5_c("BigData.txt");

    copy(istream_iterator<char>{Q5_c >> noskipws}, {}, back_inserter(answer_pali));

    for (int i = 1; i < answer_pali.length(); i++) {

        left = i - 1;
        right = i;

        while (left >= 0 && right < answer_pali.length() && answer_pali[left] == answer_pali[right]) {

            if (right - left + 1 > pali_len) {
                start_p = left;
                pali_len = right - left + 1;
            }
            left--;
            right++;
        }

        left = i - 1;
        right = i + 1;

        while (left >= 0 && right < answer_pali.length() && answer_pali[left] == answer_pali[right]) {

            if (right - left + 1 > pali_len) {
                start_p = left;
                pali_len = right - left + 1;
            }
            left--;
            right++;
        }
    }

    for (int i = start_p; i <= start_p + pali_len - 1; i++) {
        cout << answer_pali[i];
    }
    Q5_c.close();
}

int main() {
    fourA();
    fourB();   
    fourC();
    return 0;
}

 

