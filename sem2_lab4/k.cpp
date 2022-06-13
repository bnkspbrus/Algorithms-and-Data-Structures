#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%i", &n);
    int a[n];
    fill_n(a, n, 0);
    for (int ai : a) {
        printf("%i ", ai);
    }
    printf("\n");
    while(true)
    {
        int i = n - 1;
        while (i >= 0 && (a[i] != 0 || i > 0 && a[i - 1] == 1))
        {
            a[i--] = 0;
        }
        if (i == -1)
        {
            break;
        }
        a[i] = 1;
        for (int ai : a) {
            printf("%i ", ai);
        }
        printf("\n");
    }
}


