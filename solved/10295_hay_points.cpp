#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int m, n;
    unsigned long long s;
    string str;
    map<string, unsigned long long> values;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; ++i)
    {
        cin >> str;
        scanf("%llu", &values[str]);
    }

    for (int i = 0; i < n; ++i)
    {
        s = 0;
        while ((cin >> str) && str != ".")
        {
            s += values[str];
        }

        printf("%llu\n", s);
    }

    return 0;
}
