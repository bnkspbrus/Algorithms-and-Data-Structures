#include <cstdio>
#include <vector>
#include <cstdint>
#include <set>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> g;
//vector<int> d;

vector<long long> dijkstra();

int main()
{
    scanf("%i %i", &n, &m);
    g.resize(n);
    int b, e, w;
    for (int i = 0; i < m; i++) {
        scanf("%i %i %i", &b, &e, &w);
        g[b - 1].emplace_back(e - 1, w);
        g[e - 1].emplace_back(b - 1, w);
    }
    for (long long len: dijkstra()) {
        printf("%lli ", len);
    }
}

vector<long long> dijkstra()
{
    vector<long long> d(n, INT32_MAX);
    d[0] = 0;
    auto cmp = [&d](int a, int b)
    {
        if (d[a] != d[b]) {
            return d[a] < d[b];
        }
        return a < b;
    };
    set<int, decltype(cmp)> vs(cmp);
    for (int i = 0; i < n; i++) {
        vs.insert(i);
    }
    for (int i = 0; i < n; i++) {
        int v = *vs.begin();
        if (d[v] == INT32_MAX) {
            break;
        }
        vs.erase(vs.begin());
        for (const auto& p: g[v]) {
            int u = p.first, w = p.second;
            if (d[v] + w < d[u]) {
                vs.erase(u);
                d[u] = d[v] + w;
                vs.insert(u);
            }
        }
    }
    return d;
}
