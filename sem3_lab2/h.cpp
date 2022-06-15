#include <cstdio>

int N, M, S;
using namespace std;

#include <vector>
#include <algorithm>

vector<vector<int>> g;
vector<bool> mark;
vector<int> ans;

void dfs(int u);

void topSort();

int main()
{
    scanf("%i %i %i", &N, &M, &S);
    int b, e;
    g.resize(N);
    for (int i = 0; i < M; i++) {
        scanf("%i %i", &b, &e);
        g[b - 1].push_back(e - 1);
    }
    topSort();
    vector<bool> win(N, false);
    for (int v: ans) {
        for (int u: g[v]) {
            if (!win[u]) {
                win[v] = true;
                break;
            }
        }
    }
    if (win[S - 1]) {
        printf("First player wins\n");
    } else {
        printf("Second player wins\n");
    }
}

void topSort()
{
    mark.resize(N, false);
    for (int v = 0; v < N; v++) {
        if (!mark[v]) {
            dfs(v);
        }
    }
//    reverse(ans.begin(), ans.end());
}

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

