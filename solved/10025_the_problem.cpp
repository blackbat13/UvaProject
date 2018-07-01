//
// Created by black on 02.07.2018.
//

#include <iostream>
#include <cstdio>
#include <cmath>

int abs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return a * -1;
    }
}

bool check(int max, int sum, int number) {
    if (sum < number) {
        return false;
    }

    int difference = sum - number;
    while (difference > 1) {
        if (difference / 2 <= max) {
            difference -= (int) (difference / 2) * 2;
        } else {
            difference -= 2 * max;
        }
    }

    return difference == 0;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; ++n) {
        int number;
        scanf("%d", &number);

        number = abs(number);

        int max = sqrt(number * 2);
        while (true) {
            if (check(max, ((max + 1) * max) / 2, number)) {
                break;
            }

            ++max;
        }

        if (number == 0) {
            max = 3;
        }

        printf("%d\n", max);

        if (n != N) {
            printf("\n");
        }
    }
    return 0;
}