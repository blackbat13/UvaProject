#include <cstdio>

int main() {
    unsigned long long int num;
    while(scanf("%llu", &num) != EOF) {
        if(num <= 1) {
            printf("Not Exist!\n");
            continue;
        }

        unsigned long long int i = 2;
        while(i * i <= num) {
            if(num % i == 0) {
                break;
            }
            ++i;
        }

        printf("i:%llu\n", i);

        if(i * i > num) {
            i = num;
        }

        if(num * i < 2000000) {
            printf("%llu\n", num * i);
        } else {
            printf("Not Exist!\n");
        }
    }

    return 0;
}