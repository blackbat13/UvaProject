//
// Created by Damian Kurpiewski on 04.03.2017.
//

#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) && N != 0) {
        vector<int> race(N, 0);
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            int C, P;
            scanf("%d %d", &C, &P);
            if (!ok) {
                continue;
            }

            int newPosition = i + P;
            if (newPosition < 0 || newPosition >= N) {
                ok = false;
                continue;
            }

            if (race[newPosition] != 0) {
                ok = false;
                continue;
            }

            race[newPosition] = C;
        }

        if (!ok) {
            printf("-1\n");
        } else {
            for (int i = 0; i < N; ++i) {
                printf("%d ", race[i]);
            }

            printf("\n");
        }
    }

    return 0;
}