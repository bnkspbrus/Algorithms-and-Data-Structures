#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

int N, M;

long long mst();

vector<vector<pair<int, int>>> g;

int main()
{
    scanf("%i %i", &N, &M);
    int b, e, w;
    g.resize(N);
    for (int i = 0; i < M; i++) {
        scanf("%i %i %i", &b, &e, &w);
        if (b == e) {
            continue;
        }
        g[b - 1].emplace_back(w, e - 1);
        g[e - 1].emplace_back(w, b - 1);
    }
    printf("%lli\n", mst());
}

long long mst()
{
    vector<int> d(N, INT32_MAX);
    auto cmp = [&d](int a, int b)
    {
        if (d[a] != d[b]) {
            return d[a] < d[b];
        } else {
            return a < b;
        }
    };
    set<int> A = {0};
    set<int, decltype(cmp)> Q(cmp);
    for (const auto& edge: g[0]) {
        d[edge.second] = edge.first;
        Q.insert(edge.second);
    }
    long long count = 0;
    for (int i = 0; i < N - 1; i++) {
        int v = *Q.begin();
        Q.erase(Q.begin());
        count = (long long) d[v] + count;
        A.insert(v);
        for (const auto& vw: g[v]) {
            if (!A.count(vw.second)) {
                int w = vw.second;
                Q.erase(w);
                d[w] = min(d[w], vw.first);
                Q.insert(w);
            }
        }
    }
    return count;
}


