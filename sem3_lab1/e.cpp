#include <cstdio>
#include <vector>
#include <algorithm>

int n, m;

void findCutPoints();

int timer, maxColor;

using namespace std;
vector<int> tin, up;
vector<vector<pair<int, int>>> g;
vector<bool> mark;
vector<int> buf;
vector<int> colors;

int main()
{
    scanf("%i %i", &n, &m);
    int u, v;
    g.resize(n);
    tin.resize(n);
    up.resize(n);
    colors.resize(m, 0);
    mark.resize(n, false);
    for (int i = 0; i < m; i++) {
        scanf("%i %i", &u, &v);
        g[u - 1].push_back({v - 1, i});
        g[v - 1].push_back({u - 1, i});
    }
    findCutPoints();
    printf("%i\n", maxColor);
    for (int i: colors) {
        printf("%i ", i);
    }
}

void dfs(int v, int p, int pNum)
{
    mark[v] = true;
    tin[v] = up[v] = timer++;
    for (const auto& edge: g[v]) {
        int u = edge.first, num = edge.second;
        if (u == p) {
            if (num != pNum) {
                buf.push_back(num);
            }
            continue;
        }
        if (!mark[u]) {
            buf.push_back(num);
            dfs(u, v, num);
            up[v] = min(up[v], up[u]);
            if (up[u] >= tin[v]) {
                maxColor++;
                while (true) {
                    int e = buf.back();
                    buf.pop_back();
                    colors[e] = maxColor;
                    if (e == num) {
                        break;
                    }
                }
            }
        } else {
            up[v] = min(up[v], tin[u]);
            if (tin[v] > tin[u]) {
                buf.push_back(num);
            }
        }
    }
}

void findCutPoints()
{
    maxColor = timer = 0;
    for (int v = 0; v < n; v++) {
        if (!mark[v]) {
            dfs(v, -1, -1);
        }
    }
}

