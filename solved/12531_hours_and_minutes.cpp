//
// Created by black on 04.03.2017.
//

#include <cstdio>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n % 6 == 0) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}