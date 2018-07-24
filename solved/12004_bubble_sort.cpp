//
// Created by black on 24.07.2018.
//

#include <cstdio>

long long int gcd(long long a, long long b) {
    if(b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int T;
    long long int n, denominator, counter, divider;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%lld", &n);
        --n;
        counter = (1 + n) * n;
        denominator = 4;
        divider = gcd(counter, denominator);
        counter /= divider;
        denominator /= divider;
        printf("Case %d: ", t);
        if(denominator == 1) {
            printf("%lld\n", counter);
        } else {
            printf("%lld/%lld\n", counter, denominator);
        }
    }
}