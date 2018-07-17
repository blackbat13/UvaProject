#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string input;
int totalVal;
bool positive;

int makeTree(int start, int sum) {
    if (input[start + 1] == ')') {
        return -1;
    }

    char number[50];
    int index = 0;
    ++start;
    while (input[start] != '(') {
        number[index] = input[start];
        ++index;
        ++start;
    }

    number[index] = 0;
    int num = atoi(number);
    int start1, start2;
    int left, right = 0;
    start1 = start++;
    left = 1;
    while (left != right) {
        if (input[start] == '(') {
            ++left;
        } else if (input[start] == ')') {
            ++right;
        }

        ++start;
    }

    start2 = start++;
    right = 0;
    left = 1;
    while (left != right) {
        if (input[start] == '(') {
            ++left;
        } else if (input[start] == ')') {
            ++right;
        }

        ++start;
    }

    int x = makeTree(start1, sum + num);
    int y = makeTree(start2, sum + num);
    if (x == -1 && y == -1 && sum + num == totalVal) {
        positive = true;
    }

    return 0;
}

int main() {
    while (scanf("%d", &totalVal) != EOF) {
        positive = false;
        char ch;
        while (scanf("%c", &ch) && ch != '(');
        int leftParenthesis = 1;
        int rightParenthesis = 0;
        input = "(";
        while (leftParenthesis != rightParenthesis) {
            cin >> ch;
            if (ch == '(') {
                ++leftParenthesis;
            } else if (ch == ')') {
                ++rightParenthesis;
            }

            if (ch != ' ') {
                input += ch;
            }
        }

        makeTree(0, 0);
        if (positive) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}

