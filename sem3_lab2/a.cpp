#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int N;
vector<vector<int>> d;

void floyd();

int main()
{
    scanf("%i", &N); // NOLINT(cert-err34-c)
    d.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%i", &d[i][j]); // NOLINT(cert-err34-c)
        }
    }
    floyd();
    for (const auto& v: d) {
        for (int u: v) {
            printf("%i ", u);
        }
        printf("\n");
    }
}

void floyd()
{
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

