#include <cstdio>
#include <vector>
#include <algorithm>

int n, m;

void findBridges();

int timer, maxColor;

using namespace std;
vector<int> tin, up, colors, buf;
vector<vector<pair<int, int>>> g;
vector<bool> mark;

int main()
{
    scanf("%i %i", &n, &m);
    int u, v;
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    colors.resize(n, 0);
    mark.resize(n, false);
    for (int i = 0; i < m; i++) {
        scanf("%i %i", &u, &v);
        g[u - 1].push_back({v - 1, i});
        g[v - 1].push_back({u - 1, i});
    }
    findBridges();
    printf("%i\n", maxColor);
    for (int i: colors) {
        printf("%i ", i);
    }
}

void dfs(int v, int pNum)
{
    up[v] = tin[v] = timer++;
    mark[v] = true;
    buf.push_back(v);
    for (auto edge: g[v]) {
        int num = edge.second, u = edge.first;
        if (num == pNum) {
            continue;
        }
        if (mark[u]) {
            up[v] = min(up[v], tin[u]);
        } else {
            dfs(u, num);
            up[v] = min(up[v], up[u]);
        }
    }
    if (up[v] == tin[v]) {
        maxColor++;
        while (true) {
            int x = buf.back();
            buf.pop_back();
            colors[x] = maxColor;
            if (x == v) {
                break;
            }
        }
    }
}

void findBridges()
{
    timer = 0, maxColor = 0;
    for (int v = 0; v < n; v++) {
        if (!mark[v]) {
            dfs(v, -1);
        }
    }
}


