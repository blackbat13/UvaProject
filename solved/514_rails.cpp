//
// Created by black on 04.11.2018.
//

#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) && n > 0) {
        stack<int> aBack;
        int coach;
        for (int i = n; i > 0; --i) {
            aBack.push(i);
        }
        while (scanf("%d", &coach) && coach > 0) {
            stack<int> station, a = aBack;
            bool ok = true;
            if (!a.empty() && coach >= a.top()) {
                while (!a.empty() && coach >= a.top()) {
                    station.push(a.top());
                    a.pop();
                }
            }
            if (!station.empty() && coach == station.top()) {
                station.pop();
            } else {
                ok = false;
            }
            for (int i = 1; i < n; ++i) {
                scanf("%d", &coach);
                if (!ok) {
                    continue;
                }
                if (!a.empty() && coach >= a.top()) {
                    while (!a.empty() && coach >= a.top()) {
                        station.push(a.top());
                        a.pop();
                    }
                }
                if (!station.empty() && coach == station.top()) {
                    station.pop();
                } else {
                    ok = false;
                }
            }

            if (!ok) {
                printf("No\n");
            } else {
                printf("Yes\n");
            }
        }
        printf("\n");
    }
    return 0;
}