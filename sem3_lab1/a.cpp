#include <list>
#include <vector>
#include <cstdio>

using namespace std;

void topSort();

enum Color {
    WHITE,
    GREY,
    BLACK
};

list<int> ans;
vector<Color> color;
vector<vector<int>> g;
int n, m;

int main()
{
    scanf("%i %i", &n, &m);
    g.resize(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%i %i", &u, &v);
        g[u - 1].push_back(v - 1);
    }
    color.resize(n, WHITE);
    topSort();
}

bool dfs(int v)
{
    color[v] = GREY;
    for (int u: g[v]) {
        if (color[u] == WHITE) {
            if (dfs(u)) {
                return true;
            }
        } else if (color[u] == GREY) {
            return true;
        }
    }
    color[v] = BLACK;
    ans.push_front(v);
    return false;
}

void topSort()
{
    for (int v = 0; v < n; v++) {
        if (color[v] == WHITE) {
            if (dfs(v)) {
                printf("-1");
                return;
            }
        }
    }
    for (int v: ans) {
        printf("%i ", v + 1);
    }
}
