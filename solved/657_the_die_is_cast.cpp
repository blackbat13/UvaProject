//
// Created by Damian Kurpiewski on 06.07.2017.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> image;
int dice;

int X[4] = {-1, 0, 0, 1};
int Y[4] = {0, -1, 1, 0};

void fill_char(int x, int y, char c, char replace) {
    image[x][y] = replace;
    for(int k = 0; k < 4; ++k) {
        int nx, ny;
        nx = x + X[k];
        ny = y + Y[k];
        if (!(nx >= 0 && nx < image.size() && ny >= 0 && ny < image[nx].size())) {
            continue;
        }

        if(image[nx][ny] == c) {
            fill_char(nx, ny, c, replace);
        } else if(image[nx][ny] == 'X') {
            ++dice;
            fill_char(nx, ny, 'X', '*');
            fill_char(nx, ny, '*', '.');
        }
    }
}

int main() {
    int width, height;
    int throw_number = 0;
    while(scanf("%d %d", &width, &height) && width != 0 && height != 0) {
        ++throw_number;
        image = vector<string>(height);
        for(int i = 0; i < height; ++i) {
            cin >> image[i];
        }

        vector<int> results;
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(image[i][j] == '*') {
                    dice = 0;
                    fill_char(i, j, '*', '.');
                    results.push_back(dice);
                } else if(image[i][j] == 'X') {
                    dice = 1;
                    fill_char(i, j, 'X', '*');
                    fill_char(i, j, '*', '.');
                    results.push_back(dice);
                }
            }
        }

        sort(results.begin(), results.end());

        printf("Throw %d\n", throw_number);
        printf("%d", results[0]);
        for(int i = 1; i < results.size(); ++i) {
            printf(" %d", results[i]);
        }

        printf("\n\n");
    }
    return 0;
}