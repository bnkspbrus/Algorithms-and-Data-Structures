#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> b;
    b.resize(n);
    fill(b.begin(), b.end(), 1);
    vector<vector<int>> a;
    a.push_back(b);
//    for (int i = 0; i < b.size(); i++)
//    {
//        printf("%i ", b[i]);
//    }
//    printf("\n");
    while (b.size() > 1)
    {
        b[b.size() - 1]--;
        b[b.size() - 2]++;
        if (b[b.size() - 2] > b[b.size() - 1])
        {
            b[b.size() - 2] += b[b.size() - 1];
            b.pop_back();
        }
        else
        {
            while (b[b.size() - 2] * 2 <= b[b.size() - 1])
            {
                b.push_back(b[b.size() - 1] - b[b.size() - 2]);
                b[b.size() - 2] = b[b.size() - 3];
            }
        }
        reverse(b.begin(), b.end());
        a.push_back(b);
        reverse(b.begin(), b.end());
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}

