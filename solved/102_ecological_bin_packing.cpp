#include <cstdio>
#include <iostream>

using namespace std;

int min(int *w) {
    int m = 0;
    for (int i = 0; i < 6; ++i) {
        if (w[m] > w[i]) {
            m = i;
        }
    }

    return m;
}

int main() {
    int m;
    int p[3][3];
    string t[6] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    string a;
    int w[6];
    while (true) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (scanf("%d", &p[i][j]) == EOF) {
                    return 0;
                }
            }
        }

        w[0] = p[0][1] + p[0][2] + p[1][0] + p[1][1] + p[2][0] + p[2][2];
        w[1] = p[0][1] + p[0][2] + p[1][0] + p[1][2] + p[2][0] + p[2][1];
        w[2] = p[0][0] + p[0][1] + p[1][1] + p[1][2] + p[2][0] + p[2][2];
        w[3] = p[0][0] + p[0][1] + p[1][0] + p[1][2] + p[2][1] + p[2][2];
        w[4] = p[0][0] + p[0][2] + p[1][1] + p[1][2] + p[2][0] + p[2][1];
        w[5] = p[0][0] + p[0][2] + p[1][0] + p[1][1] + p[2][1] + p[2][2];

        m = min(w);
        cout << t[m] << " " << w[m] << "\n";
    }
}
