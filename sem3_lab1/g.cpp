#include <cstdio>
#include <vector>
#include <map>
#include <list>

using namespace std;

int n, m;

vector<vector<int>> g;
vector<vector<int>> gt;
map<string, int> nums;
vector<string> names;

int inv(int v)
{
    return (n + v) % (2 * n);
}

vector<int> color;

int getV(const char *name)
{
    int v;
    if (name[0] == '-') {
        v = inv(nums[name + 1]);
    } else {
        v = nums[name + 1];
    }
    return v;
}

vector<int> mark;

list<int> guests, order;

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

int maxColor;

void dfs2(int v)
{
    color[v] = maxColor;
    for (int i: gt[v]) {
        if (!color[i])
            dfs2(i);
    }
}

int main()
{
    scanf("%i %i", &n, &m);
    mark.resize(2 * n, false);
    color.resize(2 * n, 0);
    g.resize(2 * n);
    gt.resize(2 * n);
    for (int i = 0; i < n; i++) {
        char name[11];
        scanf("%s", name);
        names.emplace_back(name);
        nums.insert({name, i});
    }
    for (int i = 0; i < m; i++) {
        char name1[12], name2[12];
        scanf("%s => %s", name1, name2);
        int v1, v2;
        v1 = getV(name1);
        v2 = getV(name2);
        g[v1].push_back(v2);
        g[inv(v2)].push_back(inv(v1));
        gt[v2].push_back(v1);
        gt[inv(v1)].push_back(inv(v2));
    }
    for (int v = 0; v < 2 * n; v++) {
        if (!mark[v]) {
            dfs1(v);
        }
    }
    maxColor = 1;
    for (auto it = order.rbegin(); it != order.rend(); it++) {
        if (!color[*it]) {
            maxColor++;
            dfs2(*it);
        }
    }
    for (int i = 0; i < n; i++) {
        if (color[i] == color[inv(i)]) {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (color[i] > color[inv(i)]) {
            guests.push_back(i);
        }
    }
    printf("%i\n", (int) guests.size());
    for (int i: guests) {
        printf("%s\n", names[i].c_str());
    }
}
