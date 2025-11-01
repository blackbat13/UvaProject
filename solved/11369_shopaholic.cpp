#include <bits/stdc++.h>

using namespace std;

int main() {
    int casesCount, itemsCount;
    scanf("%d", &casesCount);
    for(int caseIndex = 0; caseIndex < casesCount; caseIndex++) {
        scanf("%d", &itemsCount);
        vector<int> prices(itemsCount);
        for (int i = 0; i < itemsCount; i++) {
            scanf("%d", &prices[i]);
        }
        sort(prices.begin(), prices.end(), greater<int>());

        int result = 0;
        for(int i = 2; i < itemsCount; i += 3) {
            result += prices[i];
        }

        printf("%d\n", result);
    }
    
    return 0;
}