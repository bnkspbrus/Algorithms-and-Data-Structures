#include <cstdio>
#include <cmath>
 
using namespace std;
 
int getSize(int n);
 
void treeBuild(int tree[], int size, int n);
 
void set(int i, int v, int tree[], int size);
 
int find(int v, int l, int x, int lx, int rx, int tree[], int size);
 
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
//    cin >> n;
//    cin >> m;
    int size = getSize(n);
    int tree[size];
    treeBuild(tree, size, n);
    while (m--) {
        int id;
        scanf("%i", &id);
//        cin >> id;
        switch (id) {
            case (1):
                int i, v;
                scanf("%i %i", &i, &v);
//                cin >> i;
//                cin >> v;
                set(i, v, tree, size);
                break;
            default:
                int l;
                scanf("%i %i", &v, &l);
//                cin >> v;
//                cin >> l;
                printf("%i\n", find(v, l, 0, 0, (size + 1) / 2, tree, size));
//                cout << find(v, l, 0, 0, (size + 1) / 2, tree, size) << endl;
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
 
void treeBuild(int tree[], int size, int n) {
    for (int i = 0; i < size; i++) {
        tree[i] = -INFINITY;
    }
    for (int i = 0; i < n; i++) {
        scanf("%i", &tree[size / 2 + i]);
//        cin >> tree[size / 2 + i];
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        tree[i] = fmax(tree[2 * i + 1], tree[2 * i + 2]);
    }
}
 
void set(int i, int v, int tree[], int size) {
    int x = size / 2 + i;
    tree[x] = v;
    while (x > 0) {
        x = (x - 1) / 2;
        tree[x] = fmax(tree[2 * x + 1], tree[2 * x + 2]);
    }
}
 
int find(int v, int l, int x, int lx, int rx, int tree[], int size) {
    if (tree[x] < v || rx <= l) {
        return -1;
    }
    if (lx >= l && rx - lx == 1 && tree[x] >= v) {
        return x - size / 2;
    }
    int m = (lx + rx) / 2;
    int ind = find(v, l, 2 * x + 1, lx, m, tree, size);
    if (ind != -1) {
        return ind;
    }
    ind = find(v, l, 2 * x + 2, m, rx, tree, size);
    return ind;
}
