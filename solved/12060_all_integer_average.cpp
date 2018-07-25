//
// Created by Damian Kurpiewski on 25.07.2018.
//

#include <cstdio>

int nwd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return nwd(b, a % b);
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int sgn(int a) {
    return a >= 0 ? 1 : -1;
}

int length(int a) {
    int result = 0;
    while(a > 0) {
        ++result;
        a /= 10;
    }

    return result;
}

int main() {
    int n, a, sum, t, div, whole, sign, numLength, sumLength, wholeLength, allLength;
    t = 0;
    while (scanf("%d", &n) && n > 0) {
        ++t;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            sum += a;
        }

        printf("Case %d:\n", t);
        sign = sgn(sum);
        sum = abs(sum);
        div = nwd(sum, n);
        sum /= div;
        n /= div;

        if (n == 1) {
            if (sign == -1) {
                printf("- ");
            }

            printf("%d\n", abs(sum));
            continue;
        }

        whole = sum / n;
        sum = sum % n;

        numLength = length(n);
        sumLength = length(sum);
        wholeLength = whole != 0 ? length(whole) : 0;
        allLength = wholeLength + numLength;
        if(sign == -1) {
            allLength += 2;
        }

        for(int i = 1; i<= allLength - sumLength; ++i) {
            printf(" ");
        }

        printf("%d\n", sum);
        if(sign == -1) {
            printf("- ");
        }

        if(whole != 0) {
            printf("%d", whole);
        }

        for(int i = 1; i <= numLength; ++i) {
            printf("-");
        }

        printf("\n");
        for(int i = 1; i<= allLength - numLength; ++i) {
            printf(" ");
        }

        printf("%d\n", n);
    }
    return 0;
}