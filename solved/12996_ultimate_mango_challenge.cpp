#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int caseCount, mangoCount, maxEat, mangoSum, currentEat;
    bool canEat;
    vector<int> mangos;
    scanf("%d", &caseCount);

    for (int caseId = 1; caseId <= caseCount; caseId++)
    {
        scanf("%d %d", &mangoCount, &maxEat);
        mangos = vector<int>(mangoCount);
        mangoSum = 0;
        canEat = true;
        for (int i = 0; i < mangoCount; i++)
        {
            scanf("%d", &mangos[i]);
            mangoSum += mangos[i];
        }

        for (int i = 0; i < mangoCount; i++)
        {
            scanf("%d", &currentEat);
            if (currentEat < mangos[i])
            {
                canEat = false;
            }
        }

        if (mangoSum > maxEat)
        {
            canEat = false;
        }

        if (canEat)
        {
            printf("Case %d: Yes\n", caseId);
        }
        else
        {
            printf("Case %d: No\n", caseId);
        }
    }

    return 0;
}