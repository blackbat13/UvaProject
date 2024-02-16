#include <cstdio>

using namespace std;

int main() {
    int n, j;
    scanf("%d", &n);
    char tab[n * 4 + 5];
    gets(tab);
    for(int i = 0; i < 5; ++i) {
        gets(tab);
        if (i == 3) {
            j = 0;
            while (j < n * 4) {
                if (tab[j] == '*') {
                    printf("2");
                } else if (tab[j + 1] == '*') {
                    printf("1");
                } else {
                    printf("3");
                }

                j += 4;
            }
        }
    }

    printf("\n");
    return 0;
}