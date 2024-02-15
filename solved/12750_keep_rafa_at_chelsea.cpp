#include <cstdio>

using namespace std;

int main() {
    int cases_count, n, last_win, result;
    char match;
    scanf("%d", &cases_count);
    for(int case_id = 1; case_id <= cases_count; ++case_id) {
        scanf("%d", &n);
        result = 0;
        last_win = 0;
        for(int i = 1; i <= n; ++i) {
            scanf(" %c", &match);
            if(match == 'W') {
                last_win = i;
            } else if (i - last_win == 3 && result == 0) {
                result = i;
            }
        }

        printf("Case %d: ", case_id);
        if (result == 0) {
            printf("Yay! Mighty Rafa persists!\n");
        } else {
            printf("%d\n", result);
        }
    }

    return 0;
}