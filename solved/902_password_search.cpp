#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int passwordSize, maxCounter, currentCounter;
    unsigned long long hash, powerOf26;
    string encodedMsg, currentStr, password;
    map<unsigned long long, int> counters;

    while (scanf("%d", &passwordSize) != EOF)
    {
        cin >> encodedMsg;

        counters.clear();
        currentStr = encodedMsg.substr(0, passwordSize);
        hash = 0;
        powerOf26 = 1;

        for (int i = 0; i < passwordSize; ++i)
        {
            hash += (currentStr[i] - 'a' + 1) * powerOf26;
            powerOf26 *= 26;
        }

        powerOf26 /= 26;

        currentCounter = ++counters[hash];
        maxCounter = currentCounter;
        password = currentStr;

        for (int i = 1; i < encodedMsg.length() - passwordSize; ++i)
        {
            hash -= (currentStr[0] - 'a' + 1);
            currentStr.erase(0, 1);
            currentStr += encodedMsg[i + passwordSize - 1];
            hash /= 26;
            hash += (currentStr[passwordSize - 1] - 'a' + 1) * powerOf26;
            currentCounter = ++counters[hash];
            if (currentCounter > maxCounter)
            {
                maxCounter = currentCounter;
                password = currentStr;
            }
        }

        printf("%s\n", password.c_str());
    }

    return 0;
}
