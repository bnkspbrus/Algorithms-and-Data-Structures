#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int k, n;
    scanf("%i %i", &k, &n);
    int a[k];
    for (int i = 0; i < k; i++)
    {
        a[i] = k - i;
    }
//    for (int i = 0; i < k; i++) {
//        a[i] = i + 1;
//    }
    for (int ai : a)
    {
        printf("%i ", ai);
    }
    printf("\n");
    int b[k + 1];
    while (true)
    {
        copy(a, a + k, b + 1);
        b[0] = n + 1;
        int i = k;
        while (i >= 1 && (b[i - 1] - b[i] < 2))
        {
            i--;
        }
        if (i >= 1)
        {
            b[i]++;
            for (int j = k; j > i; j--)
            {
                b[j] = (j < k ? b[j + 1] : 0) + 1;
            }
            copy(b + 1, b + k + 1, a);
            for (int ai : a)
            {
                printf("%i ", ai);
            }
            printf("\n");
        }
        else
        {
            break;
        }
//        copy(a, a + k, b);
//        b[k] = n + 1;
//        int i = k - 1;
//        while (i >= 0 && (b[i + 1] - b[i] < 2))
//        {
//            i--;
//        }
//        if (i >= 0)
//        {
//            b[i]++;
//            for (int j = i + 1; j < k; j++)
//            {
//                b[j] = b[j - 1] + 1;
//            }
//            copy(b, b + k, a);
//            for (int ai : a)
//            {
//                printf("%i ", ai);
//            }
//            printf("\n");
//        }
//        else
//        {
//            break;
//        }
    }
}


