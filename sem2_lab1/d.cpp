#include <cstdio>
 
using namespace std;
 
int getSize(int n);
 
void treeBuild(int tree[], int size, int n);
 
void set(int i, int tree[], int size);
 
int find(int k, int tree[], int size);
 
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    int size = getSize(n);
    int tree[size];
    treeBuild(tree, size, n);
//    for (int i = 0; i < size; i++) {
//        printf("%i ", tree[i]);
//    }
//    printf("\n");
    while (m--) {
        int id;
        scanf("%i", &id);
        if (id == 1) {
            int i;
            scanf("%i", &i);
            set(i, tree, size);
        } else {
            int k;
            scanf("%i", &k);
            printf("%i\n", find(k, tree, size));
        }
    }
}
 
int find(int k, int tree[], int size) {
    int x = 0;
    while (x < size / 2) {
        if (k > tree[2 * x + 1] - 1) {
            k -= tree[2 * x + 1];
            x = 2 * x + 2;
        } else {
            x = 2 * x + 1;
        }
    }
    return x - size / 2;
}
 
void set(int i, int tree[], int size) {
    int x = size / 2 + i;
    tree[x] = 1 - tree[x];
    while (x > 0) {
        x = (x - 1) / 2;
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
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
        tree[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%i", &tree[size / 2 + i]);
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
}
