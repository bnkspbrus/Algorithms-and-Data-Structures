#include <cstdio>

int n, m;
using namespace std;

#include <vector>
#include <queue>

int main()
{
    while (scanf("%i %i", &n, &m) == 2) {
        vector<vector<int>> gt(n);
        vector<int> out(n, 0);
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%i %i", &a, &b);
            gt[b - 1].push_back(a - 1);
            out[a - 1]++;

        }
        queue<int> q;
        vector<int> d(n, -1);
        for (int v = 0; v < n; v++) {
            if (!out[v]) {
                d[v] = 0;
                q.push(v);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (!d[v]) {
                for (int u: gt[v]) {
                    if (d[u] == -1) {
                        d[u] = 1;
                        q.push(u);
                    }
                }
            } else {
                for (int u: gt[v]) {
                    if (!(--out[u])) {
                        d[u] = 0;
                        q.push(u);
                    }
                }
            }
        }
        for (int i: d) {
            switch (i) {
                case 0:
                    printf("SECOND\n");
                    break;
                case 1:
                    printf("FIRST\n");
                    break;
                default:
                    printf("DRAW\n");
            }
        }
        printf("\n");
    }
}
