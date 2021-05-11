#include<string>
#include<sstream>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include "CuckooHashTable.h"

using namespace std;

CuckooHashTable::CuckooHashTable() {
    vector<vector<string>> contents(2, vector<string>(13));
}

int CuckooHashTable::hashCode(string value, int which) {
    int key = atoi(value.c_str());

    if (which == 1) {
        return key % LOGICAL_SIZE;
    }

    else if (which == 2) {
        return 11 - (key % 11);
    }
}

void CuckooHashTable::add(string value) {
    contents.resize(2, vector<string>(13));

    string replaced, replaced2;
    int position[2], reposition[2], reposition2[2];
    int key1, key2, nkey1, nkey2, newkey1, newkey2;
    currentSize = 0;


    while (currentSize == 0) {
        for (int i = 0; i < 2; i++) {
            position[i] = hashCode(value, i + 1);
        }
        key1 = position[0];
        key2 = position[1];

        if (contents[0][key1] == "") {
            contents[0][key1] = value;
            break;
        }

        else {
            replaced = contents[0][key1];

            for (int j = 0; j < 2; j++) {
                reposition[j] = hashCode(replaced, j + 1);
            }
            nkey1 = reposition[0];
            nkey2 = reposition[1];

            contents[0][key1] = value;

            if (contents[1][nkey2] == "") {
                contents[1][nkey2] = replaced;
                break;
            }

            else {
                replaced2 = contents[1][nkey2];
                for (int k = 0; k < 2; k++) {
                    reposition2[k] = hashCode(replaced2, k + 1);
                }
                newkey1 = reposition2[0];
                newkey2 = reposition2[1];

                contents[1][nkey2] = replaced;

                if (contents[0][newkey1] == "") {
                    contents[0][newkey1] = replaced2;
                    break;
                }

                else {
                    if (key1 == nkey1 && key2 == nkey2 && nkey1 == newkey1 && nkey2 == newkey2) {
                        currentSize++;
                        break;
                    }
                    else {
                        add(replaced2);
                        break;
                    }
                }
            }
        }
    } 
}

void CuckooHashTable::print() {
    contents.resize(2, vector<string>(13));
    if (currentSize == 0) {
        cout << "Table 1:" << endl;
        for (int i = 0; i < contents[0].size(); i++) {
            if (contents[0][i] == "") {
                cout << "-" << endl;
            }
            else {
                cout << contents[0][i] << endl;
            }
        }

        cout << "Table 2:" << endl;
        for (int j = 0; j < contents[1].size(); j++) {
            if (contents[1][j] == "") {
                cout << "-" << endl;
            }
            else {
                cout << contents[1][j] << endl;
            }
        }
    }

    else if (currentSize == 1) {
        cout << "Error: Insert causes infinite loop" << endl;
    }
}


 

