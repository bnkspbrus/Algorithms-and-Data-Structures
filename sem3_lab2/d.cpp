#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;

int N, M, K, S;
vector<vector<pair<int, int>>> gt;

vector<int> FB();

int main()
{
    scanf("%i %i %i %i", &N, &M, &K, &S);
    gt.resize(N);
    int b, e, w;
    for (int i = 0; i < M; i++) {
        scanf("%i %i %i", &b, &e, &w);
        gt[e - 1].emplace_back(b - 1, w);
    }
    for (int d: FB()) {
        if (d == INT32_MAX) {
            printf("-1\n");
        } else {
            printf("%i\n", d);
        }
    }
}

vector<int> FB()
{
    vector<int> d(N, INT32_MAX);
    d[S - 1] = 0;
    for (int i = 1; i <= K; i++) {
        vector<int> next(N, INT32_MAX);
        for (int v = 0; v < N; v++) {
            for (const auto& p: gt[v]) {
                int u = p.first, w = p.second;
                if (d[u] != INT32_MAX) {
                    next[v] = min(next[v], d[u] + w);
                }
            }
        }
        d = next;
    }
    return d;
}
