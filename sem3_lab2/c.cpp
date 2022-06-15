int N;

#include <vector>
#include <cstdio>
#include <cstdint>
#include <algorithm>

using namespace std;
#define MAX 1e9
#define IS_ABSENT 1e5

void FB();

vector<int> d;

struct edge {
    int b, e, w;

    edge(int b, int e, int w)
            : b(b), e(e), w(w)
    {
    }
};

vector<edge> edges;

int main()
{
    scanf("%i", &N);
    int w;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%i", &w);
            if (w != IS_ABSENT) {
                edges.emplace_back(i, j, w);
            }
        }
    }
    FB();
}

void FB()
{
    vector<int> p(N, -1);
    d.resize(N, 0);
    for (int i = 1; i < N; i++) {
        for (const auto& e: edges) {
            if (d[e.e] > d[e.b] + e.w) {
                d[e.e] = d[e.b] + e.w;
                p[e.e] = e.b;
            }
        }
    }
    int x = -1;
    for (const auto& e: edges) {
        if (d[e.e] > d[e.b] + e.w) {
            p[e.e] = e.b;
            x = e.e;
        }
    }
    if (x == -1) {
        printf("NO\n");
    } else {
        printf("YES\n");
        int y = x;
        for (int i = 0; i < N; i++) {
            y = p[y];
        }
        vector<int> path;
        for (int cur = y; cur != y || path.empty(); cur = p[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        printf("%i\n", (int) path.size());
        for (int v: path) {
            printf("%i ", v + 1);
        }
    }
}
