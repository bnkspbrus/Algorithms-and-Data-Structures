#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
 
using namespace std;
 
int n, log_n;
int **dp, **min_cost;
int *p, *d, *cost;
 
int lca(int v, int u);
 
void preprocess();
 
int main()
{
    scanf("%i", &n);
    log_n = log2(n);
    p = new int[n + 1]();
    cost = new int[n + 1]();
    p[1] = 1;
    cost[1] = INT_MAX;
    for (int i = 2; i <= n; i++)
    {
        scanf("%i %i", &p[i], &cost[i]);
    }
    dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = new int[log_n + 1]();
    min_cost = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        min_cost[i] = new int[log_n + 1]();
        fill_n(min_cost[i], log_n + 1, INT_MAX);
    }
    preprocess();
//    for (int i = 0; i <= n; i++)
//    {
//        for (int j = 0; j <= log_n; j++)
//            printf("min_cost[%i][%i] = %i ", i, j, min_cost[i][j]);
//        printf("\n");
//    }
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
    int min_u, min_v;
    min_u = min_v = INT_MAX;
    if (d[v] > d[u])
    {
        swap(u, v);
    }
    for (int i = log_n; i >= 0; i--)
    {
        if (d[dp[u][i]] >= d[v])
        {
            min_u = min(min_u, min_cost[u][i]);
            u = dp[u][i];
        }
    }
    if (v == u)
    {
        return min(min_u, min_v);
    }
    for (int i = log_n; i >= 0; i--)
    {
        if (dp[v][i] != dp[u][i])
        {
            min_u = min(min_u, min_cost[u][i]);
            min_v = min(min_v, min_cost[v][i]);
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    min_u = min(min_u, cost[u]);
    min_v = min(min_v, cost[v]);
    return min(min_u, min_v);
}
 
void preprocess()
{
    for (int i = 1; i <= n; i++)
    {
        min_cost[i][0] = cost[i];
        dp[i][0] = p[i];
    }
    for (int j = 1; j <= log_n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            min_cost[i][j] = min(min_cost[i][j - 1], min_cost[dp[i][j - 1]][j - 1]);
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}
