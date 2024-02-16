#include <cstdio>

using namespace std;

int main() {
    int cases_count, zero_count, one_count, question_count, result;
    char s[105], t[105];
    scanf("%d", &cases_count);
    gets(s);
    for(int case_id = 1; case_id <= cases_count; ++case_id) {
        gets(s);
        gets(t);
        zero_count = one_count = question_count = result = 0;
        for(int i = 0; s[i] != '\0'; ++i) {
            if(s[i] == t[i]) {
                continue;
            }

            if (s[i] == '1') {
                ++one_count;
            } else if (s[i] == '0') {
                ++zero_count;
            } else if (t[i] == '1') {
                ++question_count;
            } else {
                ++result;
            }
        }

        if(zero_count + question_count < one_count) {
            printf("Case %d: -1\n", case_id);
        } else {
            if (zero_count < one_count) {
                result += zero_count;
                one_count -= zero_count;
                result += one_count * 2;
                question_count -= one_count;
                result += question_count;
            } else {
                result += one_count;
                zero_count -= one_count;
                result += zero_count;
                result += question_count;
            }

            printf("Case %d: %d\n", case_id, result);
        }
    }

    return 0;
}