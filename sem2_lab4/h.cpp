#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    int a[n];
    fill_n(a, n - k, 0);
    fill_n(a + n - k, k, 1);
    for (int ai : a)
    {
        printf("%i ", ai);
    }
    printf("\n");
    while (true)
    {
        int i = n - 1;
        int counter = 0;
        while (i >= 0 && (a[i] != 1 || a[i] == 1 && (i == 0 || a[i - 1] == 1)))
        {
            if (a[i] == 1) counter++;
            i--;
        }
        if (i == -1)
        {
            break;
        }
        a[i - 1] = 1;
        fill_n(a + i, n - i - counter, 0);
        fill_n(a + n - counter, counter, 1);
        for (int ai : a)
        {
            printf("%i ", ai);
        }
        printf("\n");
    }
}


