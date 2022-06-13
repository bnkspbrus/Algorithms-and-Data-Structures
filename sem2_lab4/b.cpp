#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n, w;
        scanf("%i %i", &n, &w);
        int size = floor(log2(w)) + 1;
        int a[size];
        fill(a, a + size, 0);
        for (int i = 0; i < n; i++)
        {
            int b;
            scanf("%i", &b);
            int pow = log2(b);
            a[pow]++;
        }
        int h = 0;
        while (n)
        {
            h++;
            int max = size - 1;
            int len = w;
            while (true)
            {
                int i = max;
                while (i >= 0 && !a[i])
                {
                    i--;
                }
                if (i == -1)
                {
                    break;
                }
                a[i]--;
                n--;
                len -= pow(2, i);
                max = len == 0 ? -1 : floor(log2(len));
//                printf("max = %i\n", max);
            }
        }
        printf("%i\n", h);
    }
}


