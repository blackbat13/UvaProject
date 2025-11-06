#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string ingredients;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> ingredients;
        vector<int> counters(128, 0);
        for(char c : ingredients) {
            counters[c]++;
        }

        int result = min({counters['A'] / 3, counters['R'] / 2, counters['T'], counters['I'], counters['M'], counters['G']});
        cout << result << "\n";
    }

    return 0;
}