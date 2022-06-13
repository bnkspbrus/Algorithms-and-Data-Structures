#include <cstdio>
 
void treeBuild(long long tree[], int size, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lli", &tree[size / 2 + i]);
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
}
 
long long sum(int l, int r, int x, int lx, int rx, long long tree[]);
 
void set(int i, int v, int x, int lx, int rx, long long tree[]);
 
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    int size = n - 1;
    size |= size >> 1;
    size |= size >> 2;
    size |= size >> 4;
    size |= size >> 8;
    size |= size >> 16;
    size = size * 2 + 1;
    long long tree[size];
    for (int i = 0; i < size; i++) {
        tree[i] = 0;
    }
    treeBuild(tree, size, n);
    while (m) {
        int id;
        scanf("%i", &id);
        if (id == 1) {
            int i;
            long v;
            scanf("%i %li", &i, &v);
            set(i, v, 0, 0, (size + 1) / 2, tree);
        } else {
            int l, r;
            scanf("%i %i", &l, &r);
            printf("%lli\n", sum(l, r, 0, 0, (size + 1) / 2, tree));
        }
        m--;
    }
 
}
 
void set(int i, int v, int x, int lx, int rx, long long tree[]) {
    if (rx - lx == 1) {
        tree[x] = v;
        return;
    }
    int m = (rx + lx) / 2;
    if (i < m) {
        set(i, v, 2 * x + 1, lx, m, tree);
    } else {
        set(i, v, 2 * x + 2, m, rx, tree);
    }
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
 
}
 
long long sum(int l, int r, int x, int lx, int rx, long long tree[]) {
    if (l >= rx || lx >= r) {
        return 0;
    }
    if (lx >= l && rx <= r) {
        return tree[x];
    }
    int m = (lx + rx) / 2;
    long long s1 = sum(l, r, 2 * x + 1, lx, m, tree), s2 = sum(l, r, 2 * x + 2, m, rx, tree);
    return s1 + s2;
}

