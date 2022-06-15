#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

int n, m;

void findBridges();

int T;

using namespace std;
vector<int> tin, up;
vector<vector<int>> g;
vector<bool> mark;
vector<int> ans;
map<pair<int, int>, int> edge_num;

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
        edge_num.insert({{min(u - 1, v - 1), max(u - 1, v - 1)}, i + 1});

    }
    findBridges();
    printf("%i\n", (int) ans.size());
    sort(ans.begin(), ans.end());
    for (int e: ans) {
        printf("%i ", e);
    }
}

void dfs(int v, int p)
{
    tin[v] = T++;
    up[v] = tin[v];
    mark[v] = true;
    for (int u: g[v]) {
        if (u == p) {
            continue;
        }
        if (!mark[u]) {
            dfs(u, v);
            up[v] = min(up[v], up[u]);
        } else {
            up[v] = min(up[v], tin[u]);
        }
    }
    if (p != -1 && up[v] == tin[v]) {
        ans.push_back(edge_num[{min(p, v), max(p, v)}]);
    }
}

void findBridges()
{
    T = 0;
    for (int v = 0; v < n; v++) {
        if (!mark[v]) {
            dfs(v, -1);
        }
    }
}


