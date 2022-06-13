#include <cstdio>
#include <iostream>
#include <cmath>
 
using namespace std;
 
int getSize(int n);
 
void propagate(int x, int tree[][3], bool app[]);
 
void treeBuild(int tree[][3], bool app[], int size);
 
int sum(int l, int r, int p, int x, int lx, int rx, int tree[][3], bool app[]);
 
void build(int i, int h, int x, int lx, int rx, int tree[][3], bool app[]);
 
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
//    cin >> n >> m;
    int size = getSize(n);
    int tree[size][3];
    bool app[size];
    treeBuild(tree, app, size);
    while (m--) {
        int id;
        scanf("%i", &id);
//        cin >> id;
        switch (id) {
            case (1) :
                int i, h;
                scanf("%i %i", &i, &h);
//                cin >> i >> h;
                build(i, h, 0, 0, (size + 1) / 2, tree, app);
                break;
            default:
                int l, r, p;
                scanf("%i %i %i", &l, &r, &p);
//                cin >> l >> r >> p;
                printf("%i\n", sum(l, r, p, 0, 0, (size + 1) / 2, tree, app));
//                cout << sum(l, r, p, 0, 0, (size + 1) / 2, tree, app) << endl;
        }
    }
}
 
void propagate(int x, int tree[][3], bool app[]) {
    if (app[x]) {
        tree[2 * x + 1][0] = tree[2 * x + 2][0] = 0;
        tree[2 * x + 1][1] = tree[2 * x + 2][1] = INFINITY;
        tree[2 * x + 1][2] = tree[2 * x + 2][2] = -INFINITY;
        app[2 * x + 1] = app[2 * x + 2] = true;
        app[x] = false;
    }
}
 
int sum(int l, int r, int p, int x, int lx, int rx, int tree[][3], bool app[]) {
    if (lx >= r || rx <= l) {
        return 0;
    }
    if (lx >= l && rx <= r && (tree[x][1] > p /* min */ || tree[x][2] <= p /* max */)) {
        if (tree[x][1] > p) {
            return 0;
        }
        app[x] = true;
        int res = tree[x][0];
        tree[x][0] = 0;
        tree[x][1] = INFINITY;
        tree[x][2] = -INFINITY;
        return res;
    }
    propagate(x, tree, app);
    int m = (lx + rx) / 2;
    int s1 = sum(l, r, p, 2 * x + 1, lx, m, tree, app);
    int s2 = sum(l, r, p, 2 * x + 2, m, rx, tree, app);
    tree[x][0] = tree[2 * x + 1][0] + tree[2 * x + 2][0];
    tree[x][1] = min(tree[2 * x + 1][1], tree[2 * x + 2][1]);
    tree[x][2] = max(tree[2 * x + 1][2], tree[2 * x + 2][2]);
    return s1 + s2;
}
 
void treeBuild(int tree[][3], bool app[], int size) {
    for (int i = 0; i < size; i++) {
        tree[i][1] = INFINITY;
        tree[i][2] = -INFINITY;
        tree[i][0] = 0;
        app[i] = false;
    }
}
 
void build(int i, int h, int x, int lx, int rx, int tree[][3], bool app[]) {
    if (rx - lx == 1) {
        tree[x][0] = 1;
        tree[x][1] = tree[x][2] = h;
        return;
    }
    propagate(x, tree, app);
    int m = (rx + lx) / 2;
    if (i < m) {
        build(i, h, 2 * x + 1, lx, m, tree, app);
    } else {
        build(i, h, 2 * x + 2, m, rx, tree, app);
    }
    tree[x][0] = tree[2 * x + 1][0] + tree[2 * x + 2][0];
    tree[x][1] = min(tree[2 * x + 1][1], tree[2 * x + 2][1]);
    tree[x][2] = max(tree[2 * x + 1][2], tree[2 * x + 2][2]);
 
}
 
int getSize(int n) {
    int size = n - 1;
    size |= size >> 1;
    size |= size >> 2;
    size |= size >> 4;
    size |= size >> 8;
    size |= size >> 16;
    size = size * 2 + 1;
    return size;
}
