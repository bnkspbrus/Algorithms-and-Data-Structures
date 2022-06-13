#include <cstdio>
#include <iostream>
 
using namespace std;
 
int getSize(int n);
 
void mult(int A[2][2], int B[2][2], int C[2][2], int mod);
 
void crypt(int l, int r, int x, int lx, int rx, int tree[][2][2], int ans[2][2], int mod);
 
void treeBuild(int tree[][2][2], int size, int n, int mod);
 
int main() {
    int mod, n, m;
    scanf("%i %i %i", &mod, &n, &m);
    int size = getSize(n);
    int tree[size][2][2];
    treeBuild(tree, size, n, mod);
    int l, r;
    while (m--) {
        scanf("%i %i", &l, &r);
        int ans[2][2];
        crypt(l - 1, r, 0, 0, (size + 1) / 2, tree, ans, mod);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%i ", ans[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
 
}
 
void crypt(int l, int r, int x, int lx, int rx, int tree[][2][2], int ans[2][2], int mod) {
    if (lx >= r || rx <= l) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ans[i][j] = i == j ? 1 : 0;
            }
        }
        return;
    }
    if (lx >= l && rx <= r) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ans[i][j] = tree[x][i][j];
            }
        }
        return;
    }
    int m = (lx + rx) / 2;
    int ans1[2][2], ans2[2][2];
    crypt(l, r, 2 * x + 1, lx, m, tree, ans1, mod);
    crypt(l, r, 2 * x + 2, m, rx, tree, ans2, mod);
    mult(ans1, ans2, ans, mod);
}
 
void treeBuild(int tree[][2][2], int size, int n, int mod) {
    for (int i = size / 2; i < size; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                tree[i][j][k] = k == j ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                scanf("%i", &tree[size / 2 + i][j][k]);
            }
        }
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        mult(tree[2 * i + 1], tree[2 * i + 2], tree[i], mod);
    }
}
 
void mult(int A[2][2], int B[2][2], int C[2][2], int mod) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
        }
    }
    int r, size = 2;
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            r = A[i][k];
            for (int j = 0; j < size; j++)
                C[i][j] = (C[i][j] + r * B[k][j]) % mod;
        }
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
