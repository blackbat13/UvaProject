#include <bits/stdc++.h>

using namespace std;

int main() {
    int booksCount, targetSum;
    while(cin >> booksCount && !cin.eof()) {
        vector<int> bookPrices(booksCount);
        for (int i = 0; i < booksCount; ++i) {
            cin >> bookPrices[i];
        }

        cin >> targetSum;
        sort(bookPrices.begin(), bookPrices.end());
        int left = 0, right = booksCount - 1;
        int bestPrice1 = 0, bestPrice2 = 0;
        while (left < right) {
            int currentSum = bookPrices[left] + bookPrices[right];
            if (currentSum == targetSum) {
                bestPrice1 = bookPrices[left];
                bestPrice2 = bookPrices[right];
                left++;
                right--;
            }
            else if (currentSum < targetSum) {
                left++;
            } else {
                right--;
            }
        }
        cout << "Peter should buy books whose prices are " << bestPrice1 << " and " << bestPrice2 << "." << endl << endl;
    }

    return 0;
}