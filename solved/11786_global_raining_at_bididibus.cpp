#include <cstdio>
#include <stack>

using namespace std;

int main() {
    int test_count, result;
    char mountains[10005];
    scanf("%d", &test_count);
    gets(mountains);
    while (test_count--) {
        stack<int> down;
        result = 0;
        gets(mountains);
        for(int i = 0; mountains[i] != '\0'; ++i) {
            if (mountains[i] == '\\') {
                down.push(i);
            } else if (mountains[i] == '/' && !down.empty()) {
                result += i - down.top();
                down.pop();
            }
        }

        printf("%d\n", result);
    }

    return 0;
}