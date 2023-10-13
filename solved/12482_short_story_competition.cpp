#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N, L, C;
    int currentLength, currentLine, pages;
    string word;
    while(scanf("%d%d%d", &N, &L, &C) != EOF) {
        currentLength = 0;
        pages = 1;
        currentLine = 1;
        for(int i = 0; i < N; ++i) {
            cin >> word;
            if(word.size() + currentLength > C) {
                currentLine++;
                currentLength = word.size() + 1;
                if(currentLine > L) {
                    pages++;
                    currentLine = 1;
                }
            } else {
                currentLength += word.size() + 1;
            }
        }
        printf("%d\n", pages);
    }
}