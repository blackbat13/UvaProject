//
// Created by Damian Kurpiewski on 04.03.2017.
//

#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int S, B;
    while (scanf("%d %d", &S, &B) && S != 0) {
        vector<pair<int, int> > soldiers(S);
        for (int i = 0; i < S; ++i) {
            soldiers[i] = make_pair(i - 1, i + 1);
        }

        for (int b = 0; b < B; ++b) {
            int L, R;
            scanf("%d %d", &L, &R);
            --L;
            --R;
            if (soldiers[L].first >= 0) {
                soldiers[soldiers[L].first].second = soldiers[R].second;
                printf("%d ", soldiers[L].first + 1);
            } else {
                printf("* ");
            }

            if (soldiers[R].second < S) {
                soldiers[soldiers[R].second].first = soldiers[L].first;
                printf("%d\n", soldiers[R].second + 1);
            } else {
                printf("*\n");
            }
        }

        printf("-\n");
    }

    return 0;
}