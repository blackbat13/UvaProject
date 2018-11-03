//
// Created by black on 25.03.2017.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        int tab[n];

        for(int i = 0; i < n; ++i) {
            scanf("%d", &tab[i]);
        }

        sort(tab, tab+n);
        int a = tab[n-1], b = 0;
        for(int i = n - 2; i >= 0; --i) {
            if(a < b) {
                a += tab[i];
            } else {
                b += tab[i];
            }

            //printf("%d\n", b);
        }

        if(a > b) {
            printf("%d\n", a - b);
        } else {
            printf("%d\n", b - a);
        }
    }
}