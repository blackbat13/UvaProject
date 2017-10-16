#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<long long> > tab(n + 2, vector<long long>(n + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%lld", &tab[i][j]);
            tab[i][j] += tab[i][j - 1];
        }
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            tab[i][j] += tab[i - 1][j];
        }
    }

    long long mx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int ii = i; ii <= n; ++ii) {
                for (int jj = j; jj <= n; ++jj) {
                    long long tmp = tab[ii][jj] - tab[i - 1][jj] - tab[ii][j - 1] + tab[i - 1][j - 1];
                    if (tmp > mx)
                        mx = tmp;
                }
            }
        }
    }

    printf("%lld\n", mx);
    return 0;
}
