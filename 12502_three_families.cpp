#include <cstdio>
int main()
{
    int T, x, y, z, minutesPerHouse;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t)
    {
        scanf("%d %d %d", &x, &y, &z);
        minutesPerHouse = (x+y)*20;
        x = x * 60 - minutesPerHouse;
        printf("%d\n", (z*x)/minutesPerHouse);
    }
    return 0;
}