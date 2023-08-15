#include <cstdio>
#include <cmath>

double price(int k, int p, int a, int b, int c, int d)
{
    return (double)p * (sin((double)a * (double)k + (double)b) + cos((double)c * (double)k + (double)d) + 2);
}

int main()
{
    int p, a, b, c, d, n;
    double result, currentMax, current;
    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) != EOF)
    {
        currentMax = price(1, p, a, b, c, d);
        result = 0;
        for (int i = 2; i <= n; i++)
        {
            current = price(i, p, a, b, c, d);

            if (current > currentMax)
            {
                currentMax = current;
            }

            if (currentMax - current > result)
            {
                result = currentMax - current;
            }
        }

        printf("%.6lf\n", result);
    }
}