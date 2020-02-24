#include <bits/stdc++.h>
using namespace std;

int rbs(vector<int> a, int x) {
    int l = -1, r = a.size(), m;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (a[m] <= x)
            l = m;
        else 
            r = m;
    }
    return (l > -1 ? l + 1: 0);
}

bool prohod (vector<vector<int>> table, vector <int> time, int n, int m, int x) {
    int tm = x, mest = m;
    for (int i = 0; i < n && mest > 0; i++) {
        mest -= rbs(table[i], tm);
        tm += time[i];
    }
    return mest <= 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> table(n);
    vector <int> time(n);
    int maxx = -1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> time[i] >> k;
        table[i] = vector<int>(k);
        for (int j = 0; j < k; j++) {
            cin >> table[i][j];
            maxx = max(table[i][j], maxx);
        }
    }
    maxx += 1;
    int minn = -1;
    while (minn < maxx - 1) {
        int x = (minn + maxx) / 2;
        if (prohod(table, time, n, m, x))
            maxx = x;
        else 
            minn = x;
    }
    int answ = maxx;
    for (int i = 0; i < n; i++)
        answ += time[i];
    cout << answ;
    return 0;
}
