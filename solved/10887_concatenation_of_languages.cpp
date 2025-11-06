#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    for(int t = 0; t < testCases; ++t) {
        int n, m;
        cin >> n >> m;

        string tmp;
        getline(cin, tmp); // Consume the newline character after reading m

        vector<string> languageA(n);
        for(int i = 0; i < n; ++i) {
            getline(cin, languageA[i]);
        }

        vector<string> languageB(m);
        for(int i = 0; i < m; ++i) {
            getline(cin, languageB[i]);
        }

        set<string> concatenatedLanguages;
        for(const string& a : languageA) {
            for(const string& b : languageB) {
                concatenatedLanguages.insert(a + b);
            }
        }

        cout << "Case " << t + 1 << ": " << concatenatedLanguages.size() << "\n";
    }

    return 0;
}