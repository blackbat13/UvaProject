#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf("%d", &n);
    vector<long long int> heights(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &heights[i]);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        long long int query;
        scanf("%lld", &query);
        long long int firstShorter = -1, firstTaller = -1;
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (heights[mid] < query) {
                firstShorter = heights[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        left = 0;
        right = n - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (heights[mid] > query) {
                firstTaller = heights[mid];
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (firstShorter == -1) {
            printf("X ");
        } else {
            printf("%lld ", firstShorter);
        }

        if (firstTaller == -1) {
            printf("X\n");
        } else {
            printf("%lld\n", firstTaller);
        }
    }

    return 0;
}