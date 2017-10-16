#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> tab(1000000);

int ile(long long n, int l) {
    if (n == 1) {
        return l + 1;
    }

    if (n < 1000000) {
        if (tab[n] != 0) {
            return l + tab[n];
        }

        if (n % 2 == 0) {
            return ile(n / 2, l + 1);
        } else {
            return ile(3 * n + 1, l + 1);
        }
    }

    if (n % 2 == 0) {
        return ile(n / 2, l + 1);
    } else {
        return ile(3 * n + 1, l + 1);
    }
}

int main() {
    for (int i = 1; i < 1000000; ++i) {
        if (tab[i] == 0)
            tab[i] = ile(i, 0);
    }

    int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
        printf("%d %d ", i, j);
        if (j < i) {
            swap(i, j);
        }

        printf("%d\n", *max_element(tab.begin() + i, tab.begin() + j + 1));
    }

    return 0;
}
