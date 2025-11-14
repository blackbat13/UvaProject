#include <cstdio>

using namespace std;

int main() {
    int t, n, num, numCopy, prices[36], costs[37];
    scanf("%d", &t);
    for(int testCase = 1; testCase <= t; ++testCase) {
        for(int i = 0; i < 36; ++i) {
            scanf("%d", &prices[i]);
        }

        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &num);
            for(int j = 2; j <= 36; ++j) {
                numCopy = num;
                costs[j] = 0;
                while(numCopy) {
                    costs[j] += prices[numCopy % j];
                    numCopy /= j;
                }
            }
        }
    }
    return 0;
}