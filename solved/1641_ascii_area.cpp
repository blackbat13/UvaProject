#include <cstdio>

using namespace std;

int main() {
    int w, h, last, result;
    char line[105];
    while(scanf("%d %d", &h, &w) != EOF) {
        gets(line);
        result = 0;
        while(h-- && gets(line)) {
            last = -1;
            for(int i = 0; i < w; ++i) {
                if(line[i] != '.') {
                    if (last == -1) {
                        last = i;
                    } else {
                        result += i - last;
                        last = -1;
                    }
                }
            } 
        }

        printf("%d\n", result);
    }

    return 0;
}