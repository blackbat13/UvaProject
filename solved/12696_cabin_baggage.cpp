#include <cstdio>

using namespace std;

int main() {
    int t, total = 0;
    double l, w, d, wg;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        scanf("%lf %lf %lf %lf", &l, &w, &d, &wg);
        if(((l <= 56.0 && w <= 45.0 && d <= 25.0) || (l + w + d <= 125.0)) && wg <= 7.0) {
            printf("1\n");
            ++total;
        } else {
            printf("0\n");
        }
    }

    printf("%d\n", total);
    return 0;
}