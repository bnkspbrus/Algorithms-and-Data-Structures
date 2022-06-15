#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int N, M, maxColor;
vector<vector<int>> g, gr;
vector<set<int>> cond;
vector<int> order;
vector<int> mark, color;

void dfs2(int v);

void dfs1(int v);

int getCountEdges();

int main()
{
    scanf("%i %i", &N, &M);
    int b, e;
    g.resize(N);
    gr.resize(N);
    mark.resize(N, false);
    for (int i = 0; i < M; i++) {
        scanf("%i %i", &b, &e);
        g[b - 1].push_back(e - 1);
        gr[e - 1].push_back(b - 1);
    }
    for (int v = 0; v < N; v++) {
        if (!mark[v]) {
            dfs1(v);
        }
    }
    color.resize(N, 0);
    reverse(order.begin(), order.end());
    maxColor = 0;
    for (int v: order) {
        if (!color[v]) {
            maxColor++;
            dfs2(v);
        }
    }
    cond.resize(maxColor + 1);
    printf("%i\n", getCountEdges());
}

int getCountEdges()
{
    int count = 0;
    for (int v = 0; v < N; v++) {
        for (int u: g[v]) {
            if (color[u] != color[v]) {
                cond[color[v]].insert(color[u]);
            }
        }
    }
    for (const auto& v: cond) {
        count += (int) v.size();
    }
    return count;
}

void dfs2(int v)
{
    color[v] = maxColor;
    for (int u: gr[v]) {
        if (!color[u]) {
            dfs2(u);
        }
    }
}

void dfs1(int v)
{
    mark[v] = true;
    for (int u: g[v]) {
        if (!mark[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}


