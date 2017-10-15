//
// Created by blackbat on 15.10.2017.
//

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int N;
    string a, b;
    map<string, string> slogans;
    scanf("%d", &N);
    getline(cin, a);
    while (N--) {
        getline(cin, a);
        getline(cin, b);
        slogans[a] = b;
    }

    scanf("%d", &N);
    getline(cin, a);
    while (N--) {
        getline(cin, a);
        cout << slogans[a] << endl;
    }

    return 0;
}