#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int test_count, numbers_count, result, num;
    scanf("%d", &test_count);
    for(int test_case = 1; test_case <= test_count; ++test_case) {
        scanf("%d", &numbers_count);
        scanf("%d", &result);
        for(int i = 1; i < numbers_count; ++i) {
            scanf("%d", &num);
            result = max(result, num);
        }

        printf("Case %d: %d\n", test_case, result);
    }

    return 0;
}