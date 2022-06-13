#include <cstdio>
#include <iostream>
 
using namespace std;
 
int getSize(int n);
 
void add(int l, int r, int v, int x, int lx, int rx, long long tree[][2], bool app[]);
 
void treeBuild(long long tree[][2], bool app[], int size);
 
void propagate(int x, long long tree[][2], bool app[]);
 
long long sum(int l, int r, int x, int lx, int rx, long long tree[][2], bool app[]);
 
void set(int l, int r, int v, int x, int lx, int rx, long long tree[][2], bool app[]);
 
 
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
//    FILE *f = fopen("in.txt", "r");
//    cin >> n;
//    cin >> m;=
    int size = getSize(n);
    long long tree[size][2];
    bool app[size];
    treeBuild(tree, app, size);
    while (m--) {
        int id, l, r;
        scanf("%i %i %i", &id, &l, &r);
        switch (id) {
            case (1) :
                int v;
                scanf("%i", &v);
                set(l, r, v, 0, 0, (size + 1) / 2, tree, app);
                break;
            case (2) :
                scanf("%i", &v);
                add(l, r, v, 0, 0, (size + 1) / 2, tree, app);
                break;
            default:
                printf("%lli\n", sum(l, r, 0, 0, (size + 1) / 2, tree, app));
        }
    }
 
}
 
void treeBuild(long long tree[][2], bool app[], int size) {
    for (int i = 0; i < size; i++) {
        tree[i][1] = tree[i][0] = 0;
        app[i] = false;
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
 
void propagate(int x, long long tree[][2], bool app[]) {
    if (app[x]) {
        tree[2 * x + 1][1] = tree[2 * x + 2][1] = tree[x][1];
        tree[2 * x + 1][0] = tree[2 * x + 2][0] = 0;
        tree[x][1] = 0;
        app[2 * x + 1] = app[2 * x + 2] = true;
        app[x] = false;
    }
}
 
void add(int l, int r, int v, int x, int lx, int rx, long long tree[][2], bool app[]) {
    if (lx >= r || rx <= l) {
        return;
    }
    if (lx >= l && rx <= r) {
        tree[x][1] += v;
        return;
    }
    propagate(x, tree, app);
    int m = (rx + lx) / 2;
    add(l, r, v, 2 * x + 1, lx, m, tree, app);
    add(l, r, v, 2 * x + 2, m, rx, tree, app);
    tree[x][0] =
            tree[2 * x + 1][0] + tree[2 * x + 2][0] + (tree[2 * x + 1][1] + tree[2 * x + 2][1]) * (m - lx);
}
 
void set(int l, int r, int v, int x, int lx, int rx, long long tree[][2], bool app[]) {
    if (lx >= r || rx <= l) {
        return;
    }
    if (lx >= l && rx <= r) {
        tree[x][1] = v;
        tree[x][0] = 0;
        app[x] = true;
        return;
    }
    propagate(x, tree, app);
    tree[2 * x + 1][1] += tree[x][1];
    tree[2 * x + 2][1] += tree[x][1];
    tree[x][1] = 0;
    int m = (lx + rx) / 2;
    set(l, r, v, 2 * x + 1, lx, m, tree, app);
    set(l, r, v, 2 * x + 2, m, rx, tree, app);
    tree[x][0] =
            tree[2 * x + 1][0] + tree[2 * x + 2][0] + (tree[2 * x + 1][1] + tree[2 * x + 2][1]) * (m - lx);
}
 
long long sum(int l, int r, int x, int lx, int rx, long long tree[][2], bool app[]) {
    if (lx >= r || rx <= l) {
        return 0;
    }
    if (lx >= l && rx <= r) {
        return (rx - lx) * tree[x][1] + tree[x][0];
    }
    int m = (rx + lx) / 2;
    long long s1 = sum(l, r, 2 * x + 1, lx, m, tree, app);
    long long s2 = sum(l, r, 2 * x + 2, m, rx, tree, app);
    long long sum = (min(r, rx) - max(l, lx)) * tree[x][1];
    if (!app[x]) {
        sum += s1 + s2;
    }
    return sum;
}
