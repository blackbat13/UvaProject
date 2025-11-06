#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<long long> specialNumbers = { 1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};
    long long num;

    while(cin >> num && num != 0) {
        if(specialNumbers.count(num)) {
            cout << "Special\n";
        } else {
            cout << "Ordinary\n";
        }
    }
    
    return 0;
}