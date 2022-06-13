#include <algorithm>
#include <iostream>

int n;

int factorial(int i);

using namespace std;

void prev_perm(int *a);

int main()
{
    scanf("%i", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
    for (int i = 0; i < n; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < factorial(n) - 1; i++) {
        for (int k = n - 2; k >= 0; k--)
        {
            if (a[k] > a[k + 1])
            {
                int max = k + 1;
                for (int j = k + 1; j < n; j++)
                {
                    if (a[j] > a[max] && a[j] < a[k])
                    {
                        max = j;
                    }
                }
                swap(a[k], a[max]);
                reverse(a + k + 1, a + n);
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            printf("%i ", a[j]);
        }
        printf("\n");
    }
}

int factorial(int i)
{
    return (i == 1 || i == 0) ? 1 : factorial(i - 1) * i;
}


