#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    char s[400002];
    fgets(s, 400002, stdin);
    int n = (int) strlen(s);
    s[n - 1] = '`';
    vector<vector<int>> sort(27);
    for (int i = 0; i < n; i++) {
        sort[s[i] - '`'].push_back(i);
    }
    vector<int> p;
    for (const auto& v: sort) {
        for (int i: v) {
            p.push_back(i);
        }
    }
    vector<int> c(n);
    c[p[0]] = 0;
    for (int i = 1; i < p.size(); i++) {
        c[p[i]] = c[p[i - 1]];
        if (s[p[i]] != s[p[i - 1]]) {
            c[p[i]]++;
        }
    }
    int len = 1;
    while (len < n) {
        for (int& i: p) {
            i = i - len;
            if (i < 0) {
                i += n;
            }
        }
        vector<vector<int>> c_sort(c.size());
        for (int k: p) {
            c_sort[c[k]].push_back(k);
        }
        int j = 0;
        for (const auto& list: c_sort) {
            for (int i: list) {
                p[j++] = i;
            }
        }
        vector<int> _c(n);
        _c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            _c[p[i]] = _c[p[i - 1]] + 1;
            if (c[p[i]] == c[p[i - 1]] && c[p[i] + len] == c[p[i - 1] + len]) {
                _c[p[i]]--;
            }
        }
        c = _c;
        len <<= 1;
    }
    vector<int> l(n - 1);
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = c[i];
        if (k > 0) {
            k--;
        }
        while (s[p[x - 1] + k] == s[p[x] + k]) {
            k++;
        }
        l[x - 1] = k;
    }
    long long cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cnt += n - 1 - p[i + 1] - l[i];
    }
    printf("%lli", cnt);
}
