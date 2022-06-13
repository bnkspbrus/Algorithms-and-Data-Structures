#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int k, n;
    scanf("%i %i", &n, &k);
    int a[n];
    fill_n(a, n, 0);
    for (int i : a)
    {
        printf("%i ", i);
    }
    printf("\n");
    while (true)
    {
        int i = n - 1;
        while (i >= 0 && a[i] == k - 1) {
            a[i--] = 0;
        }
        if (i == -1) {
            break;
        }
        a[i]++;
        for (int ai : a)
        {
            printf("%i ", ai);
        }
        printf("\n");
    }
}


