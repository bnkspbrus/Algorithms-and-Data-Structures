#include <cstdio>
#include <vector>
#include <algorithm>

int n, m;

void find();

int T;

using namespace std;
vector<int> tin, up;
vector<vector<int>> g;
vector<bool> mark;
vector<int> ans;

int main()
{
    scanf("%i %i", &n, &m);
    int u, v;
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    mark.resize(n, false);
    for (int i = 0; i < m; i++) {
        scanf("%i %i", &u, &v);
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);

    }
    find();
    printf("%i\n", (int) ans.size());
    sort(ans.begin(), ans.end());
    for (int e: ans) {
        printf("%i ", e);
    }
}

void dfs(int v, int p)
{
    mark[v] = true;
    tin[v] = up[v] = T++;
    int child = 0;
    bool isCutPoint = false;
    for (int u: g[v]) {
        if (u == p) {
            continue;
        }
        if (mark[u]) {
            up[v] = min(up[v], tin[u]);
        } else {
            dfs(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] >= tin[v] && p != -1) {
                isCutPoint = true;
            }
            child++;
        }
    }
    if (isCutPoint || p == -1 && child > 1) {
        ans.push_back(v + 1);
    }
}

void find()
{
    T = 0;
    for (int v = 0; v < n; v++) {
        if (!mark[v]) {
            dfs(v, -1);
        }
    }
}

