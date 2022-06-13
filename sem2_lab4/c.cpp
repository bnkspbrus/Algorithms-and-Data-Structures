#include <cstdio>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int bin_search(int (*a)[2], long long &key, int n);

void quick_sort(int (*a)[2], int l, int r);

int part(int (*a)[2], int l, int r);

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        long long w;
        scanf("%i %lli", &n, &w);
        int a[n][2];
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &a[i][0]);
            a[i][1] = i + 1;
        }
        quick_sort(a, 0, n - 1);
        vector<int> ans;
        long long min = ceil(w / 2.0);
        while (true)
        {
            if (n == 0) {
                printf("-1\n");
                break;
            }
            int ind = bin_search(a, w, n);
            if (ind == -1) {
                printf("-1\n");
                break;
            }
            int elem = a[ind][0];
            if (elem >= min)
            {
                printf("%zu\n", ans.size() + 1);
                printf("%i ", a[ind][1]);
                while (!ans.empty())
                {
                    printf("%i ", ans.back());
                    ans.pop_back();
                }
                printf("\n");
                break;
            }
            else
            {
                w -= elem;
                min -= elem;
                ans.push_back(a[ind][1]);
                n = ind;
            }
        }
    }
}

int part(int (*a)[2], int l, int r)
{
    int v = a[(l + r) / 2][0];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (a[i][0] < v)
            i++;
        while (a[j][0] > v)
            j--;
        if (i >= j)
            break;
        swap(a[i++], a[j--]);
    }
    return j;
}

void quick_sort(int (*a)[2], int l, int r)
{
    if (l < r)
    {
        int q = part(a, l, r);
        quick_sort(a, l, q);
        quick_sort(a, q + 1, r);
    }
}

int bin_search(int (*a)[2], long long &key, int n)
{
    int l = -1;
    int r = n;
    while (l < r - 1)
    {
        int m = (l + r) / 2;
        if (a[m][0] <= key)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return l;
}


