#include <cstdio>

using namespace std;

int main() {
    int n, m, result, a;
    bool ok;
    while(scanf("%d %d", &n, &m) != EOF) {
        result = 0;
        for(int i = 0; i < n; ++i) {
            ok = true;
            for(int j = 0; j < m; ++j) {
                scanf("%d", &a);
                if(a == 0) {
                    ok = false;
                }
            }

            if (ok) {
                ++result;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}