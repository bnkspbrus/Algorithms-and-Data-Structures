#include <cstdio>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int n, log_n;
int **dp;
int *p, *d;
 
int lca(int v, int u);
 
void preprocess();
 
int main()
{
    scanf("%i", &n);
    log_n = log2(n);
    p = new int[n + 1]();
    p[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        scanf("%i", &p[i]);
    }
    dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[log_n + 1]();
    preprocess();
    d = new int[n + 1]();
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[p[i]] + 1;
    }
    int m;
    scanf("%i", &m);
    while (m--)
    {
        int v, u;
        scanf("%i %i", &v, &u);
        printf("%i\n", lca(v, u));
    }
}
 
int lca(int v, int u)
{
    if (d[v] > d[u])
    {
        swap(u, v);
    }
    for (int i = log_n; i >= 0; i--)
    {
        if (d[dp[u][i]] >= d[v])
        {
            u = dp[u][i];
        }
    }
    if (v == u)
    {
        return v;
    }
    for (int i = log_n; i >= 0; i--)
    {
        if (dp[v][i] != dp[u][i])
        {
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    return p[v];
}
 
void preprocess()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = p[i];
    }
    for (int j = 1; j <= log_n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}
