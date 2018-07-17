#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

unsigned long long len(vector<int> series) {
    unsigned long long n = series.size();
    vector<int> T(n + 1);
    T[0] = 0;
    for (int i = 1; i <= n; ++i) {
        T[i] = (int) INFINITY;
    }

    for (int i = 0; i < n; ++i) {
        long long s = lower_bound(T.begin(), T.begin() + n + 1, series[i]) - T.begin();
        T[s] = series[i];
    }

    unsigned long long i = n;
    while (T[i] == (int) INFINITY) {
        i--;
    }

    return i;
}

int main() {
    int a;
    unsigned long long n;
    scanf("%llu", &n);
    int tab[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tab[i]);
    }

    while (scanf("%d", &a) != EOF) {
        vector<int> series(n);
        series[a - 1] = 1;
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &a);
            series[a - 1] = i;
        }

        for (int i = 0; i < n; ++i) {
            series[i] = tab[series[i] - 1];
        }

        printf("%llu\n", len(series));
    }

    return 0;
}
