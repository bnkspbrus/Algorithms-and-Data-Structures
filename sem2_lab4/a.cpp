#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%i", &n);
        int a[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%i", &a[j]);
        }
        int size = 0;
        int lock[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%i", &lock[j]);
            if (!lock[j]) size++;
        }
        int s[size];
        int pos = 0;
        for (int j = 0; j < n; j++)
        {
            if (!lock[j])
            {
                s[pos++] = a[j];
            }
        }
        sort(s, s + size);
        pos = size - 1;
        for (int j = 0; j < n; j++)
        {
            if (!lock[j])
            {
                a[j] = s[pos--];
            }
        }
        for (int ai : a)
        {
            printf("%i ", ai);
        }
        printf("\n");
    }
}

