#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int casesCount, mobileCount, dif;
    vector<string> mobileNumbers;
    string jalilNumber;

    scanf("%d", &casesCount);

    for (int caseId = 1; caseId <= casesCount; ++caseId)
    {
        scanf("%d", &mobileCount);
        printf("Case %d:\n", caseId);
        mobileNumbers = vector<string>(mobileCount);

        for (int i = 0; i < mobileCount; ++i)
        {
            cin >> mobileNumbers[i];
        }

        cin >> jalilNumber;

        for (auto &currentNumber : mobileNumbers)
        {
            dif = 0;
            for (int i = 0; i < currentNumber.size(); ++i)
            {
                if (currentNumber[i] != jalilNumber[i])
                {
                    ++dif;
                }
            }

            if (dif <= 1)
            {
                printf("%s\n", currentNumber.c_str());
            }
        }
    }

    return 0;
}