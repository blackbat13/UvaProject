#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int players, rounds, tmp, mx, mxIndex;
    vector<int> playersPoints;
    while (scanf("%d %d", &players, &rounds) != EOF)
    {
        playersPoints = vector<int>(players, 0);
        for (int j = 0; j < rounds; ++j)
        {
            for (int i = 0; i < players; ++i)
            {
                scanf("%d", &tmp);
                playersPoints[i] += tmp;
            }
        }

        mx = playersPoints[players - 1];
        mxIndex = players - 1;
        for (int i = players - 1; i >= 0; --i)
        {
            if (playersPoints[i] > mx)
            {
                mx = playersPoints[i];
                mxIndex = i;
            }
        }

        printf("%d\n", mxIndex + 1);
    }

    return 0;
}