#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>
#include <cfloat>
#include <cmath>

using namespace std;

int N;

long double mst();

vector<pair<int, int>> coord;

int main()
{
    scanf("%i", &N);
    int x, y;
    coord.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%i %i", &x, &y);
        coord[i] = {x, y};
    }
    printf("%0.10Lf\n", mst());
}

long double mst()
{
    vector<bool> A(N, false);
    vector<int> d(N);
    int x1 = coord[0].first, y1 = coord[0].second;
    for (int v = 1; v < N; v++) {
        int x2 = coord[v].first, y2 = coord[v].second;
        d[v] = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }
    A[0] = true;
    long double count = 0;
    for (int i = 0; i < N - 1; i++) {
        int v;
        int minD = INT32_MAX;
        for (int j = 0; j < N; j++) {
            if (!A[j]) {
                if (d[j] < minD) {
                    v = j;
                    minD = d[v];
                }
            }
        }
        count = sqrt(d[v]) + count;
        A[v] = true;
        x1 = coord[v].first, y1 = coord[v].second;
        for (int w = 0; w < N; w++) {
            if (!A[w]) {
                int x2 = coord[w].first, y2 = coord[w].second;
                auto s = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                d[w] = min(d[w], s);
            }
        }
    }
    return count;
}




