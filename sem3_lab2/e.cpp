int n, m, s;

#include <vector>
#include <cstdio>
#include <algorithm>

typedef long long lli;

using namespace std;
#define INF 2e18
vector<bool> inf;

void FB();

vector<lli> d;
vector<vector<int>> g;
vector<vector<pair<int, lli>>> gt;
vector<bool> used;

int main()
{
    scanf("%i %i %i", &n, &m, &s);
    int b, e;
    g.resize(n);
    gt.resize(n);
    lli w;
    for (int i = 0; i < m; i++) {
        scanf("%i %i %lli", &b, &e, &w);
        g[b - 1].push_back(e - 1);
        gt[e - 1].emplace_back(b - 1, w);
    }
    FB();
    for (int i = 0; i < n; i++) {
        if (d[i] == INF) {
            printf("*\n");
        } else if (used[i]) {
            printf("-\n");
        } else {
            printf("%lli\n", d[i]);
        }
    }
}

void dfs(int v)
{
    used[v] = true;
    for (int u: g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

void FB()
{
    inf.resize(n, false);
    d.resize(n, INF);
    d[s - 1] = 0;
    for (int i = 1; i <= n; i++) {
        vector<lli> nd(d);
        for (int v = 0; v < n; v++) {
            for (const auto& p: gt[v]) {
                int u = p.first;
                lli w = p.second;
                if (d[u] != INF) {
                    if (d[v] > d[u] + w) {
                        if (i == n) {
                            inf[v] = true;
                        } else {
                            nd[v] = max((lli) -INF, d[u] + w);
                        }
                    }
                }
            }
        }
        d = nd;
    }
    used.resize(n, false);
    for (int v = 0; v < n; v++) {
        if (!used[v] && inf[v]) {
            dfs(v);
        }
    }
}
