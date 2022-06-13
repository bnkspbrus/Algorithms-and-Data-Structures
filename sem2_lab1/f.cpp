#include <iostream>
#include <cmath>
#include <climits>
 
using namespace std;
 
int getSize(int n);
 
long long mmin(int l, int r, int x, int lx, int rx, long long tree[][2]);
 
void treeBuild(long long tree[][2], int size, int n);
 
void add(int l, int r, int v, int x, int lx, int rx, long long tree[][2]);
 
int main() {
    int n, m;
//    cin >> n;
//    cin >> m;
    scanf("%i %i", &n, &m);
    int size = getSize(n);
    long long tree[size][2];
    treeBuild(tree, size, n);
    int id, l, r;
    while (m--) {
//        cin >> id;
//        cin >> l;
//        cin >> r;
        scanf("%i %i %i", &id, &l, &r);
        switch (id) {
            case (1):
                int v;
//                cin >> v;
                scanf("%i", &v);
                add(l, r, v, 0, 0, (size + 1) / 2, tree);
                break;
            default:
//                cout << mmin(l, r, 0, 0, (size + 1) / 2, tree) << endl;
                printf("%lli\n", mmin(l, r, 0, 0, (size + 1) / 2, tree));
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
 
void treeBuild(long long tree[][2], int size, int n) {
    for (int i = size / 2; i < size / 2 + n; i++) {
        tree[i][1] = tree[i][0] = 0;
    }
    for (int i = size / 2 + n; i < size; i++) {
        tree[i][0] = INFINITY;
        tree[i][1] = 0;
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        tree[i][0] = fmin(tree[2 * i + 1][0], tree[2 * i + 2][0]);
        tree[i][1] = 0;
    }
}
 
void add(int l, int r, int v, int x, int lx, int rx, long long tree[][2]) {
    if (lx >= l && rx <= r) {
        tree[x][1] += v;
        return;
    }
    if (l >= rx || lx >= r) {
        return;
    }
    int m = (lx + rx) / 2;
    add(l, r, v, 2 * x + 1, lx, m, tree);
    add(l, r, v, 2 * x + 2, m, rx, tree);
    tree[x][0] = fmin(tree[2 * x + 1][0] + tree[2 * x + 1][1], tree[2 * x + 2][0] + tree[2 * x + 2][1]);
}
 
long long mmin(int l, int r, int x, int lx, int rx, long long tree[][2]) {
    if (l >= rx || lx >= r) {
        return INFINITY;
    }
    if (lx >= l && rx <= r) {
        return tree[x][0] + tree[x][1];
    }
    int m = (lx + rx) / 2;
    long long min1 = mmin(l, r, 2 * x + 1, lx, m, tree), min2 = mmin(l, r, 2 * x + 2, m, rx, tree);
    return fmin(min1, min2) + tree[x][1];
}
