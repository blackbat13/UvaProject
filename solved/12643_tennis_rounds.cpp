#include <cstdio>

using namespace std;

int main() {
    int n, i, j, result;
    while(scanf("%d %d %d", &n, &i, &j) != EOF) {
        result = 0;
        while (i != j) {
            i = (i + 1) / 2;
            j = (j + 1) / 2;
            ++result;
        }

        printf("%d\n", result);
    }

    return 0;
}