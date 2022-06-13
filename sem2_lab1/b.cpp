#include <cstdio>
#include <cmath>
 
void treeBuild(int tree[][2], int size, int n);
 
void set(int i, int v, int x, int lx, int rx, int tree[][2]);
 
void mmin(int l, int r, int x, int lx, int rx, int tree[][2], int ans[2]);
 
 
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
    int tree[size][2];
    for (int i = 0; i < size; i++) {
        tree[i][0] = INFINITY;
        tree[i][1] = 0;
    }
    treeBuild(tree, size, n);
//    printf("array: ");
//    for (int i = 0; i < size; i++) {
//        printf("%i ", tree[i][0]);
//    }
//    printf("\n");
    while (m) {
        int id;
        scanf("%i", &id);
        if (id == 1) {
            int i, v;
            scanf("%i %i", &i, &v);
            set(i, v, 0, 0, (size + 1) / 2, tree);
        } else {
            int l, r;
            scanf("%i %i", &l, &r);
            int ans[2];
            ans[0] = ans[1] = 0;
            mmin(l, r, 0, 0, (size + 1) / 2, tree, ans);
            printf("%i %i\n", ans[0], ans[1]);
        }
        m--;
    }
}
 
void set(int i, int v, int x, int lx, int rx, int tree[][2]) {
    if (rx - lx == 1) {
        tree[x][0] = v;
        tree[x][1] = 1;
        return;
    }
    int m = (rx + lx) / 2;
    if (i < m) {
        set(i, v, 2 * x + 1, lx, m, tree);
    } else {
        set(i, v, 2 * x + 2, m, rx, tree);
    }
    if (tree[2 * x + 1][0] > tree[2 * x + 2][0]) {
        tree[x][0] = tree[2 * x + 2][0];
        tree[x][1] = tree[2 * x + 2][1];
    } else if (tree[2 * x + 1][0] < tree[2 * x + 2][0]) {
        tree[x][0] = tree[2 * x + 1][0];
        tree[x][1] = tree[2 * x + 1][1];
    } else {
        tree[x][0] = tree[2 * x + 2][0];
        tree[x][1] = tree[2 * x + 1][1] + tree[2 * x + 2][1];
    }
 
}
 
void treeBuild(int tree[][2], int size, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%i", &tree[size / 2 + i][0]);
        tree[size / 2 + i][1] = 1;
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        if (tree[2 * i + 1][0] > tree[2 * i + 2][0]) {
            tree[i][0] = tree[2 * i + 2][0];
            tree[i][1] = tree[2 * i + 2][1];
        } else if (tree[2 * i + 1][0] < tree[2 * i + 2][0]) {
            tree[i][0] = tree[2 * i + 1][0];
            tree[i][1] = tree[2 * i + 1][1];
        } else {
            tree[i][0] = tree[2 * i + 2][0];
            tree[i][1] = tree[2 * i + 1][1] + tree[2 * i + 2][1];
        }
    }
}
 
void mmin(int l, int r, int x, int lx, int rx, int tree[][2], int ans[2]) {
    if (l >= rx || lx >= r) {
        return;
    }
    if (lx >= l && rx <= r) {
        ans[0] = tree[x][0];
        ans[1] = tree[x][1];
        return;
    }
    int m = (lx + rx) / 2;
    int ans1[2], ans2[2];
    ans1[1] = ans2[1] = 0;
    ans1[0] = ans2[0] = INFINITY;
    mmin(l, r, 2 * x + 1, lx, m, tree, ans1);
    mmin(l, r, 2 * x + 2, m, rx, tree, ans2);
    if (ans1[0] > ans2[0]) {
        ans[0] = ans2[0];
        ans[1] = ans2[1];
    } else if (ans1[0] < ans2[0]) {
        ans[0] = ans1[0];
        ans[1] = ans1[1];
    } else {
        ans[0] = ans1[0];
        ans[1] = ans1[1] + ans2[1];
    }
}
