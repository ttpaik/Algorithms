#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define S 99
#define filename "maze.txt"

int solvedimension() {
    int num, counter = 0;
    ifstream board(filename);
    string content;

    while (getline(board, content)) {
        for (int i = 0; i < content.length(); i++) {
            if (content[i] == '0' || content[i] == '1') {
                counter++;
            }
        }
        num = sqrt(counter);
    }
    board.close();
    return num;
}

int N = solvedimension();
int s_way = N * N;

void solveDFS(int sArr[S][S], int row, int col, int n) {
    if (row == N - 1 && col == N - 1) {
        if (s_way > n) {
            s_way = n;
        }  
    }

    sArr[row][col] = 0;

    if (sArr[row + 1][col] == 1 && row < N - 1)
        solveDFS(sArr, row + 1, col, n + 1);

    if (sArr[row - 1][col] == 1 && row > 0)
        solveDFS(sArr, row - 1, col, n + 1);
    
    if (sArr[row][col + 1] == 1 && col < N - 1)
        solveDFS(sArr, row, col + 1, n + 1);

    if (sArr[row][col - 1] == 1 && col > 0)
        solveDFS(sArr, row, col - 1, n + 1);
    
    sArr[row][col] = 1;
}

int main() {
    char cArr[S][S];
    int iArr[S][S];
    int count = 0, count2 = 0;
    ifstream maze(filename);
    string mazeArr;
    
    while (getline(maze, mazeArr)) {
        for (int i = 0; i < N; i++) {
            if (mazeArr[i] == '0' || mazeArr[i] == '1')
                cArr[count][i] = mazeArr[i];
        }
        count++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            iArr[i][j] = cArr[i][j] - '0';
        }
    }

    solveDFS(iArr, 0, 0, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (iArr[i][j] == 1) {
                count2++;
            }
        }
    }
    
    if (s_way < count2) {
        cout << s_way;
    }

    else {
        cout << 0;
    }

    return 0;
}