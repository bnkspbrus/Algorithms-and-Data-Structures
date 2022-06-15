#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;
int n, m;
vector<vector<int>> g;

vector<bool> mark;
vector<int> ans;

void dfs(int u)
{
    mark[u] = true;
    for (int v: g[u]) {
        if (!mark[v]) {
            dfs(v);
        }
    }
    ans.push_back(u);
}

void topSort()
{
    mark.resize(n, false);
    for (int v = 0; v < n; v++) {
        if (!mark[v]) {
            dfs(v);
        }
    }
}

#include <set>

int main()
{
    scanf("%i %i", &n, &m);
    g.resize(n);
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%i %i", &x, &y);
        g[x - 1].push_back(y - 1);
    }
    topSort();
    vector<int> grundy(n, -1);
    for (int v: ans) {
        vector<bool> available(n, true);
        for (int u: g[v]) {
            available[grundy[u]] = false;
        }
        for (int i = 0; grundy[v] == -1 && i < n; i++) {
            if (available[i]) {
                grundy[v] = i;
            }
        }
    }
    for (int gr: grundy) {
        printf("%i\n", gr);
    }
}
