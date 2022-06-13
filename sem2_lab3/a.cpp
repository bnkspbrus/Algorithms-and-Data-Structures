#include <iostream>
#include <fstream>
#include <cmath>
 
using namespace std;
 
int n, lon_n;
int **dp;
int *p;
 
void preprocess();
 
int main()
{
    scanf("%i", &n);
    lon_n = log2(n);
    p = new int[n + 1];
    dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[lon_n + 1]();
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%i", &p[i]);
    }
    preprocess();
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= lon_n; j++) {
//            printf("d[%i][%i] = %i ", i, j, dp[i][j]);
//        }
//        printf("\n");
//    }
    for (int i = 1; i <= n; i++)
    {
        printf("%i: ", i);
        for (int j = 0; j <= lon_n && dp[i][j]; j++)
        {
            printf("%i ", dp[i][j]);
        }
        printf("\n");
    }
}
 
void preprocess()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = p[i];
    }
    for (int j = 1; j <= lon_n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

