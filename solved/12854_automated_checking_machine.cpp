#include <cstdio>

int main()
{
    int tab[5], a;
    bool result;
    while (scanf("%d %d %d %d %d", &tab[0], &tab[1], &tab[2], &tab[3], &tab[4]) != EOF)
    {
        result = true;
        for (int i = 0; i < 5; i++)
        {
            scanf("%d", &a);
            if (a == tab[i])
            {
                result = false;
            }
        }

        if (result)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }

    return 0;
}