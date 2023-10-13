#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int T, R, C;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &R, &C);
        vector<vector<unsigned long long> > tab = vector<vector<unsigned long long> >(R + 1, vector<unsigned long long>(C + 1,0));
        tab[1][C] = 1;
        for(int i = 1; i <= R; ++i) {
            for(int j = C - 1; j >= 0; --j) {
                tab[i][j] = tab[i][j + 1] + tab[i - 1][j];
            }
        }

        printf("%llu\n", tab[R][0]);
    }
    return 0;
}