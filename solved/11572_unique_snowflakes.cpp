//
// Created by Damian Kurpiewski on 14.10.2017.
//

#include <map>
#include <cstdio>
using namespace std;

int main() {
    int t, n, a;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int result = 0;
        int maxResult = 0;
        int begin = 0;
        map<int,int> location;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            if(location[a] == 0 || location[a] < begin) {
                location[a] = i;
                ++result;
            } else {
                maxResult = max(result, maxResult);
                begin = location[a] + 1;
                result = i - begin + 1;
                location[a] = i;
            }
        }

        printf("%d\n", max(result, maxResult));
    }
    return 0;
}