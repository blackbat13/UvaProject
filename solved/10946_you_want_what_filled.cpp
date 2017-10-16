//
// Created by Damian Kurpiewski on 05.07.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int X[4] = {-1, 0, 0, 1};
int Y[4] = {0, -1, 1, 0};
int hole_size;

vector<string> matrix;

void fill_hole(int x, int y, char c) {
    if (!(x >= 0 && x < matrix.size() && y >= 0 && y < matrix[x].size() && matrix[x][y] == c)) {
        return;
    }

    ++hole_size;
    matrix[x][y] = '.';
    for (int k = 0; k < 4; ++k) {
        int nx, ny;
        nx = x + X[k];
        ny = y + Y[k];
        fill_hole(nx, ny, c);
    }
}

int main() {
    int x, y;
    char c;
    int p_number = 0;
    while (cin >> x >> y && (x != 0 && y != 0)) {
        ++p_number;
        matrix = vector<string>(x);
        for (int i = 0; i < x; ++i) {
            cin >> matrix[i];
        }

        vector<pair<int, char> > result;

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (matrix[i][j] == '.') {
                    continue;
                }

                hole_size = 0;
                c = matrix[i][j];
                fill_hole(i, j, c);
                result.push_back(make_pair(-hole_size, c));
            }
        }

        sort(result.begin(), result.end());
        printf("Problem %d:\n", p_number);
        for(int i = 0; i < result.size(); ++i) {
            printf("%c %d\n", result[i].second, -result[i].first);
        }
    }
}