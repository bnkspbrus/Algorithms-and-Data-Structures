#include <cstdio>
#include <iostream>
#include <cmath>
 
int min(int l, int r, int x, int lx, int rx, int tree[][2], bool app[]);
 
void propagate(int x, int tree[][2], bool app[]);
 
void treeBuild(int tree[][2], bool app[], int size);
 
void set(int l, int r, int v, int x, int lx, int rx, int tree[][2], bool app[]);
 
using namespace std;
 
int getSize(int n);
 
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
//    cin >> n;
//    cin >> m;
    int size = getSize(n);
    int tree[size][2];
    bool app[size];
    treeBuild(tree, app, size);
    while (m--) {
        int id, l, r;
        scanf("%i %i %i", &id, &l, &r);
//        cin >> id;
//        cin >> l;
//        cin >> r;
        switch (id) {
            case (1):
                int v;
                scanf("%i", &v);
//                cin >> v;
                set(l, r, v, 0, 0, (size + 1) / 2, tree, app);
                break;
            default:
                int ans = min(l, r, 0, 0, (size + 1) / 2, tree, app);
                printf("%i\n", ans);
//                cout << ans << endl;
 
        }
    }
 
}
 
int min(int l, int r, int x, int lx, int rx, int tree[][2], bool app[]) {
    if (lx >= r || rx <= l) {
        return INFINITY;
    }
    if (lx >= l && rx <= r) {
        return app[x] ? tree[x][1] : tree[x][0];
    }
    int m = (lx + rx) / 2;
    int min1 = min(l, r, 2 * x + 1, lx, m, tree, app);
    int min2 = min(l, r, 2 * x + 2, m, rx, tree, app);
    return app[x] ? tree[x][1] : fmin(min1, min2);
}
 
void set(int l, int r, int v, int x, int lx, int rx, int tree[][2], bool app[]) {
    if (lx >= r || rx <= l) {
        return;
    }
    if (lx >= l && rx <= r) {
        tree[x][1] = v;
        app[x] = true;
        return;
    }
    propagate(x, tree, app);
    int m = (lx + rx) / 2;
    set(l, r, v, 2 * x + 1, lx, m, tree, app);
    set(l, r, v, 2 * x + 2, m, rx, tree, app);
    int min1 = app[2 * x + 1] ? tree[2 * x + 1][1] : tree[2 * x + 1][0];
    int min2 = app[2 * x + 2] ? tree[2 * x + 2][1] : tree[2 * x + 2][0];
    tree[x][0] = fmin(min1, min2);
}
 
void propagate(int x, int tree[][2], bool app[]) {
    if (app[x]) {
        tree[2 * x + 1][1] = tree[x][1];
        tree[2 * x + 2][1] = tree[x][1];
        app[2 * x + 1] = true;
        app[2 * x + 2] = true;
        app[x] = false;
    }
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
 
void treeBuild(int tree[][2], bool app[], int size) {
    for (int i = 0; i < size; i++) {
        tree[i][0] = 0;
        app[i] = false;
    }
}
