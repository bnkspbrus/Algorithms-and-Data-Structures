#include <cstdio>

int n, m;
using namespace std;
typedef long long lli;
#define INF 1e18

#include <vector>
#include <set>
#include <algorithm>

vector<vector<lli>> d;

vector<vector<pair<int, int>>> g;

void nextPerm(int perm[]);

void dijkstra(int s);

int main()
{
    scanf("%i %i", &n, &m);
    g.resize(n);
    d.resize(n);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%i %i %i", &u, &v, &w);
        g[u - 1].emplace_back(v - 1, w);
        g[v - 1].emplace_back(u - 1, w);
    }
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    dijkstra(a - 1);
    dijkstra(b - 1);
    dijkstra(c - 1);
    lli minPath = INF;
    int perm[]{a - 1, b - 1, c - 1};
    sort(perm, perm + 3);
    for (int i = 0; i < 6; i++, nextPerm(perm)) {
        if (d[perm[0]][perm[1]] == INF || d[perm[1]][perm[2]] == INF) {
            continue;
        }
        lli curPath = d[perm[0]][perm[1]] + d[perm[1]][perm[2]];
        minPath = min(minPath, curPath);
    }
    if (minPath == INF) {
        printf("-1\n");
    } else {
        printf("%lli\n", minPath);
    }
}

void nextPerm(int perm[])
{
    for (int i = 1; i >= 0; i--) {
        if (perm[i] < perm[i + 1]) {
            int min = i + 1;
            for (int j = i + 1; j < 3; j++) {
                if (perm[j] < perm[min] && perm[j] > perm[i]) {
                    min = j;
                }
            }
            swap(perm[i], perm[min]);
            reverse(perm + i + 1, perm + 3);
            return;
        }
    }
}

void dijkstra(int s)
{
    d[s].resize(n, INF);
    d[s][s] = 0;
    auto cmp = [s](int a, int b)
    {
        if (d[s][a] != d[s][b]) {
            return d[s][a] < d[s][b];
        }
        return a < b;
    };
    set<int, decltype(cmp)> vs(cmp);
    for (int i = 0; i < n; i++) {
        vs.insert(i);
    }
    for (int i = 0; i < n; i++) {
        int v = *vs.begin();
        if (d[s][v] == INF) {
            break;
        }
        vs.erase(vs.begin());
        for (const auto& p: g[v]) {
            int u = p.first, w = p.second;
            if (d[s][v] + w < d[s][u]) {
                vs.erase(u);
                d[s][u] = d[s][v] + w;
                vs.insert(u);
            }
        }
    }
}
