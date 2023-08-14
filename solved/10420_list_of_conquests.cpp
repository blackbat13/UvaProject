#include <cstdio>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n;
    string country;
    map<string, int> counters;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        cin >> country;
        counters[country]++;
        getline(cin, country);
    }

    for (auto &el : counters)
    {
        printf("%s %d\n", el.first.c_str(), el.second);
    }

    return 0;
}
