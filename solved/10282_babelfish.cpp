#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    char c;
    string translation, word;
    map<string, string> dictionary;

    while (scanf("%c", &c) && c != '\n')
    {
        ungetc(c, stdin);
        cin >> translation >> word;
        dictionary[word] = translation;
        scanf("%c", &c);
    }

    while (cin >> word && !cin.eof())
    {
        if (dictionary[word] == "")
        {
            printf("eh\n");
        }
        else
        {
            cout << dictionary[word] << endl;
        }
    }

    return 0;
}
