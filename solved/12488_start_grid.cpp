#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        vector<int> start(n), positions(n + 1);
        for(int i = 0; i < n; i++) {
            scanf("%d", &start[i]);
        }
        for(int i = 0; i < n; i++) {
            int finishValue;
            scanf("%d", &finishValue);
            positions[finishValue] = i;
        }
        int result = 0;
        int index = n - 1;
        while(index >= 0) {
            if(positions[start[index]] > index) {
                swap(start[index], start[index + 1]);
                result++;
                index++;
            } else {
                index--;
            }
        }

        printf("%d\n", result);
    }
    return 0;
}