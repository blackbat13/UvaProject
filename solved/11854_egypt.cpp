//
// Created by black on 24.03.2017.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int tab[3];
    while (scanf("%d %d %d", &tab[0], &tab[1], &tab[2]) && (tab[0] != 0 || tab[1] != 0 || tab[2] != 0)) {
        sort(tab, tab+3);
        if(tab[0]*tab[0] + tab[1]*tab[1] == tab[2]*tab[2]) {
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }
    return 0;
}