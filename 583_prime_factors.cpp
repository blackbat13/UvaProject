//
// Created by black on 25.03.2017.
//

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> prime(2147483647, true);
vector<unsigned int> primes;

void sieve() {
    prime[0] = false;
    prime[1] = false;

    int sq = (int)sqrt(2147483647);

    primes.push_back(2);

    for(unsigned int i = 3; i <= sq; i += 2) {
        if(!prime[i]) {
            continue;
        }

        primes.push_back(i);

        for(unsigned int j = i*2; j <= sq; j += i) {
            prime[j] = false;
        }
    }
}

int main() {
    int a;
    sieve();
    while(scanf("%d", &a) && a!=0) {
        printf("%d = ", a);
        bool first = true;
        if(a < 0) {
            printf("-1");
            a *= -1;
            first = false;
        }

        int p = 0;
        while(a > 0 && p < primes.size()) {
            if(a % primes[p] == 0) {
                if(first) {
                    printf("%d", primes[p]);
                    first = false;
                } else {
                    printf(" x %d", primes[p]);
                }

                a /= primes[p];
            } else {
                ++p;
            }
        }

        if(a > 1) {
            if(first) {
                printf("%d", a);
            } else {
                printf(" x %d", a);
            }
        }

        printf("\n");
    }
}