#include <cstdio>
#include <iostream>

using namespace std;
int flipperValue[100][100];
int flipperCost[100][100];
bool flipperPos[100][100];

int main() {
    int n, m, wallCost, holesNumber, x, y, ballMove, life, pointsSum;
    int movement[4][2];
    pointsSum = 0;
    movement[0][0] = 1;
    movement[0][1] = 0;
    movement[1][0] = 0;
    movement[1][1] = 1;
    movement[2][0] = -1;
    movement[2][1] = 0;
    movement[3][0] = 0;
    movement[3][1] = -1;
    scanf("%d %d", &n, &m);
    scanf("%d", &wallCost);
    scanf("%d", &holesNumber);
    for (int i = 0; i < holesNumber; ++i) {
        int cost, value;
        scanf("%d %d %d %d", &x, &y, &value, &cost);
        flipperValue[x][y] = value;
        flipperCost[x][y] = cost;
        flipperPos[x][y] = true;
    }

    while (scanf("%d %d %d %d", &x, &y, &ballMove, &life) != EOF) {
        int points = 0;
        while (life > 1) {
            int nx = x, ny = y;
            nx += movement[ballMove][0];
            ny += movement[ballMove][1];
            if (nx >= n || ny >= m || nx <= 1 || ny <= 1) {
                life -= wallCost;
                --ballMove;
                if (ballMove < 0) {
                    ballMove = 3;
                }
            } else if (flipperPos[nx][ny]) {
                points += flipperValue[nx][ny];
                life -= flipperCost[nx][ny];
                --ballMove;
                if (ballMove < 0) {
                    ballMove = 3;
                }
            } else {
                x = nx;
                y = ny;
            }

            --life;
        }

        printf("%d\n", points);
        pointsSum += points;
    }

    printf("%d\n", pointsSum);
    return 0;
}
