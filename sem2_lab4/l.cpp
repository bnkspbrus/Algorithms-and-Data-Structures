#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

//void print(char a[], int n)
//{
//    for (int i = 0; i < 2 * n; i++)
//    {
//
//    }
//    printf("\n");
//}

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    char s[2 * n + 1];
    fill(s, s + n, '(');
    fill(s + n, s + 2 * n, ')');
    s[2 * n] = '\0';
    int ind = 1;
    if (ind % k == 0)
    {
        printf("%s\n", s);
    }
    while (true)
    {
        int cc = 0, co = 0;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                co++;
                if (cc > co)
                {
                    break;
                }
            }
            else
            {
                cc++;
            }
        }
        int pos = 2 * n - co - cc;
        if (pos == 0)
        {
            break;
        }
        else
        {
            s[pos++] = ')';
            for (int i = 0; i < co; i++)
            {
                s[pos++] = '(';
            }
            for (int i = 0; i < cc - 1; i++)
            {
                s[pos++] = ')';
            }
            ind++;
            if (ind % k == 0)
            {
                printf("%s\n", s);
            }
        }
    }
}


