#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string beds;

    while(cin >> beds) {
        int distances[beds.length()];
        int curr_dist = beds.length() + 100;
        int result = 0;
        for(int i = 0; i < beds.length(); ++i) {
            if (beds[i] == 'X') {
                curr_dist = 0;
                distances[i] = 0;
            } else {
                distances[i] = curr_dist;
                curr_dist += 1;
            }
        }

        curr_dist = beds.length() + 100;
        for(int i = beds.length() - 1; i >= 0; --i) {
            if (beds[i] == 'X') {
                curr_dist = 0;
                distances[i] = min(distances[i], curr_dist);
            } else {
                distances[i] = min(distances[i], curr_dist);
                curr_dist += 1;
            }

            result = max(result, distances[i]);
        }

        printf("%d\n", result);
    }

    return 0;
}
