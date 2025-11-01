#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    while(scanf("%d", &k) != EOF) {
        vector<priority_queue<int, vector<int>, greater<int>>> minHeaps(k);
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                int value;
                scanf("%d", &value);
                minHeaps[i].push(value);
            }
        }
        for(int i = 0; i < k; i++) {
            int sum = 0;
            for(int j = 0; j < k; j++) {
                sum += minHeaps[j].top();
                minHeaps[j].pop();
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}