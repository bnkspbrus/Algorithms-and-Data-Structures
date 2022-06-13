#include <iostream>
#include <cmath>
 
using namespace std;
 
int getSize(int n);
 
void treeBuild(int tree[][5], int size);
 
void set(int l, int r, char col, int x, int lx, int rx, int tree[][5]);
 
void propagate(int x, int tree[][5], int len);
 
int main() {
    int n;
//    cin >> n;
    scanf("%i", &n);
    int op[n][3];
    int l = INFINITY;
    int r = 0;
    for (int i = 0; i < n; i++) {
        char c;
//        cin >> c >> op[i][1] >> op[i][2];
        scanf("\n%c %i %i", &c, &op[i][1], &op[i][2]);
        op[i][0] = c;
        op[i][2] += op[i][1];
        l = min(l, op[i][1]);
        r = max(r, op[i][2]);
    }
    int size = getSize(r - l);
    int tree[size][5]; // 0 - sum "1", 1 - sum seg, 2 - app, 3 - "1" left, 4 - "1" right
    treeBuild(tree, size);
    for (int i = 0; i < n; i++) {
        set(op[i][1] - l, op[i][2] - l, op[i][0], 0, 0, (size + 1) / 2, tree);
//        cout << tree[0][1] << " " << tree[0][0] << endl;
        printf("%i %i\n", tree[0][1], tree[0][0]);
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
 
void treeBuild(int tree[][5], int size) {
    for (int i = 0; i < size; i++) {
        tree[i][0] = 0;
        tree[i][1] = 0;
        if (i >= size / 2) {
            tree[i][2] = 'W';
        } else {
            tree[i][2] = 'N';
        }
        tree[i][3] = tree[i][4] = 0;
    }
}
 
void set(int l, int r, char col, int x, int lx, int rx, int tree[][5]) {
    if (lx >= r || rx <= l) {
        return;
    }
    if (lx >= l && rx <= r) {
        if (col == 'W') {
            tree[x][0] = tree[x][1] = tree[x][3] = tree[x][4] = 0;
            tree[x][2] = 'W';
            return;
        }
        tree[x][0] = rx - lx;
        tree[x][1] = tree[x][3] = tree[x][4] = 1;
        tree[x][2] = 'B';
        return;
    }
    int m = (lx + rx) / 2;
    propagate(x, tree, m - lx);
    set(l, r, col, 2 * x + 1, lx, m, tree);
    set(l, r, col, 2 * x + 2, m, rx, tree);
    tree[x][0] = tree[2 * x + 1][0] + tree[2 * x + 2][0];
    int sumSeg = tree[2 * x + 1][1] + tree[2 * x + 2][1];
    if (tree[2 * x + 1][4] == 1 && tree[2 * x + 2][3] == 1) {
        sumSeg--;
    }
    tree[x][1] = sumSeg;
    tree[x][3] = tree[2 * x + 1][3];
    tree[x][4] = tree[2 * x + 2][4];
}
 
void propagate(int x, int tree[][5], int len) {
    if (tree[x][2] != 'N') {
        tree[2 * x + 1][2] = tree[2 * x + 2][2] = tree[x][2];
        if (tree[x][2] == 'W') {
            tree[2 * x + 1][0] = tree[2 * x + 2][0] = tree[2 * x + 1][1] = tree[2 * x + 2][1] = tree[2 * x +
                                                                                                     1][3] = tree[
                    2 * x + 2][3] = tree[2 * x + 1][4] = tree[2 * x + 2][4] = 0;
        } else {
            tree[2 * x + 1][0] = tree[2 * x + 2][0] = len;
            tree[2 * x + 1][1] = tree[2 * x + 2][1] = tree[2 * x + 1][3] = tree[2 * x + 2][3] = tree[2 * x +
                                                                                                     1][4] = tree[
                    2 * x + 2][4] = 1;
        }
        tree[x][2] = 'N';
    }
}
