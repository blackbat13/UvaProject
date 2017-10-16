//
// Created by black on 24.03.2017.
//

#include <cstdio>

bool prime[1000000];

void sieve() {
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i < 1000000; ++i) {
        prime[i] = true;
    }

    for(int i = 2; i < 1000000; ++i) {
        if(!prime[i]) {
            continue;
        }

        for(int j = i*2; j < 1000000; j += i) {
            prime[j] = false;
        }
    }
}

int reverse(int a) {
    int b = 0;
    while(a > 0) {
        b *= 10;
        b += a % 10;
        a /= 10;
    }

    return b;
}

int main() {
    sieve();
    int a;
    while(scanf("%d", &a) != EOF) {
        if(!prime[a]) {
            printf("%d is not prime.\n", a);
        } else if(prime[reverse(a)] && reverse(a) != a) {
            printf("%d is emirp.\n", a);
        } else {
            printf("%d is prime.\n", a);
        }
    }
    return 0;
}