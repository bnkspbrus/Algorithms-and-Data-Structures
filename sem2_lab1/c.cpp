#include <cstdio>
#include <cmath>
 
int getSize(int n);
 
void treeBuild(double tree[][4], int size, int n);
 
void set(int i, int v, int x, int lx, int rx, double tree[][4]);
 
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    int size = getSize(n);
    double tree[size][4];
    for (int i = 0; i < size; i++) {
        tree[i][0] = 0;
        for (int j = 1; j < 4; j++) {
            tree[i][j] = -INFINITY;
        }
    }
    treeBuild(tree, size, n);
//    for (int i = 0; i < size; i++) {
//        printf("i = %i: ", i);
//        for (int j = 0; j < 4; j++) {
//            printf("%lli ", tree[i][j]);
//        }
//        printf("\n");
//    }
    printf("%.0lf\n", tree[0][3]);
    while (m--) {
        int i, v;
        scanf("%i %i", &i, &v);
        set(i, v, 0, 0, (size + 1) / 2, tree);
        printf("%.0lf\n", tree[0][3]);
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
 
void treeBuild(double tree[][4], int size, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &tree[size / 2 + i][0]);
        if (tree[size / 2 + i][0] < 0) {
            tree[size / 2 + i][1] = 0;
        } else {
            tree[size / 2 + i][1] = tree[size / 2 + i][0];
        }
        tree[size / 2 + i][2] = tree[size / 2 + i][3] = tree[size / 2 + i][1];
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        tree[i][0] = tree[2 * i + 1][0] + tree[2 * i + 2][0];
        tree[i][1] = fmax(tree[2 * i + 1][1], tree[2 * i + 1][0] + tree[2 * i + 2][1]);
        tree[i][2] = fmax(tree[2 * i + 2][2], tree[2 * i + 1][2] + tree[2 * i + 2][0]);
        tree[i][3] = fmax(tree[2 * i + 1][3], fmax(tree[2 * i + 2][3], tree[2 * i + 1][2] + tree[2 * i + 2][1]));
    }
}
 
void set(int i, int v, int x, int lx, int rx, double tree[][4]) {
    if (rx - lx == 1) {
        tree[x][0] = v;
        if (tree[x][0] < 0) {
            tree[x][1] = 0;
        } else {
            tree[x][1] = tree[x][0];
        }
        tree[x][2] = tree[x][3] = tree[x][1];
        return;
    }
    int m = (rx + lx) / 2;
    if (i < m) {
        set(i, v, 2 * x + 1, lx, m, tree);
    } else {
        set(i, v, 2 * x + 2, m, rx, tree);
    }
    tree[x][0] = tree[2 * x + 1][0] + tree[2 * x + 2][0];
    tree[x][1] = fmax(tree[2 * x + 1][1], tree[2 * x + 1][0] + tree[2 * x + 2][1]);
    tree[x][2] = fmax(tree[2 * x + 2][2], tree[2 * x + 1][2] + tree[2 * x + 2][0]);
    tree[x][3] = fmax(tree[2 * x + 1][3], fmax(tree[2 * x + 2][3], tree[2 * x + 1][2] + tree[2 * x + 2][1]));
 
}
