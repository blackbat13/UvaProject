//
// Created by Damian Kurpiewski on 06.07.2017.
//
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int X[4] = {-1, 0, 0, 1};
int Y[4] = {0, -1, 1, 0};
vector<string> grid;
int water_size;

void count(int x, int y) {
    if (!(x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() && grid[x][y] == '0')) {
        return;
    }

    ++water_size;
    grid[x][y] = '1';
    for (int k = 0; k < 4; ++k) {
        int nx, ny;
        nx = x + X[k];
        ny = y + Y[k];
        count(nx, ny);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        if(t > 1) {
            printf("\n");
        }
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        string str;
        getline(cin, str);
        grid.clear();
        while(getline(cin, str) && !cin.eof() && str.length() > 0) {
            grid.push_back(str);
        }

        water_size = 0;
        count(x, y);
        printf("%d\n", water_size);
    }
    return 0;
}