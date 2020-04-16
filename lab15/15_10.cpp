//OnlyVim 16.04.2020
#include <bits/stdc++.h>

using namespace std;

typedef long long base; 
typedef pair<int, int> point;      
typedef complex<double> comp;

const int N = 3e5 + 100;
const int LOG = 18;

struct fen {
    int a[N];
    void add(int i, int d) {
        while (i < N) {
            a[i] += d;
            i |= (i + 1);
        }
    }
    int get(int i) {
        int ans = 0;
        while (i >= 0) {
            ans += a[i];
            i &= (i + 1);
            --i;
        }
        return ans;
    }
} box[2];

int n, cnt = 1;
int up[LOG][N];
vector<int> edge[N];
vector<int> who[N][2];
vector<int> nxt[N];
char f[N];
int ask[N][2];

void dfs_init(int i, int p = -1) {
    if (p != -1) 
        edge[p].push_back(i);
    for (auto j : nxt[i]) 
        dfs_init(j, p);
    for (auto j : who[i][0]) 
        dfs_init(j, i);
    for (auto j : who[i][1]) 
        dfs_init(j, i);
}

int t, curt;
int p[N][2][2];
int h[N];

void dfs(int i) {
    p[i][t][0] = curt++;
    for (auto j : edge[i]) {
        up[0][j] = i;
        h[j] = h[i] + 1;
        dfs(j);
    }
    p[i][t][1] = curt;
}

int lca(int a, int b) {
    if (h[a] > h[b]) swap(a, b);
    for (int t = LOG; t--;) {
        if (h[up[t][b]] >= h[a]) {
            b = up[t][b];
            ++t;
        }
    }
    if (a == b) return a;
    for (int t = LOG; t--;) {
        if (up[t][a] != up[t][b]) {
            a = up[t][a];
            b = up[t][b];
            ++t;
        }
    }
    return up[0][a];
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    cnt = 1;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        if (f[i] == 'l' || f[i] == 'r' || f[i] == 'd') {
            cin >> ask[i][0];
        } else {
            cin >> ask[i][0] >> ask[i][1];
        }
        if (f[i] == 'l') {
            who[ask[i][0]][0].push_back(cnt);
            ++cnt;
        }
        if (f[i] == 'r') {
            who[ask[i][0]][1].push_back(cnt);
            ++cnt;
        }
        if (f[i] == 'a') {
            nxt[ask[i][1]].push_back(cnt);
            ++cnt;
        }
    }
    for (int i = 0; i < cnt; ++i) {
        reverse(nxt[i].begin(), nxt[i].end());
        reverse(who[i][0].begin(), who[i][0].end());
    }
    dfs_init(0);
    for (t = 0; t < 2; ++t) {
        curt = 0;
        dfs(0);
        for (int i = 0; i < n; ++i) {
            reverse(edge[i].begin(), edge[i].end());
        }
    }
    for (int i = 0; i + 1 < LOG; ++i) {
        for (int j = 0; j < n; ++j) {
            up[i + 1][j] = up[i][up[i][j]];
        }
    }
    box[0].add(p[0][0][0], 1);
    box[1].add(p[0][1][0], 1);
    cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (f[i] == 'l' || f[i] == 'r' || f[i] == 'a') {
            box[0].add(p[cnt][0][0], 1);
            box[1].add(p[cnt][1][0], 1);
            ++cnt;
        } 
        if (f[i] == 'd') {
            box[0].add(p[ask[i][0]][0][0], -1);
            box[1].add(p[ask[i][0]][1][0], -1);
        }
        if (f[i] == 'p') {
            int c = lca(ask[i][0], ask[i][1]);
            cout << h[ask[i][0]] + h[ask[i][1]] - h[c] * 2 + 1 << '\n';
        }
        if (f[i] == 'q') {
            int a = ask[i][0];
            int b = ask[i][1];
            if (p[a][0][0] > p[b][0][0]) swap(a, b);
            int c = lca(a, b);
            int s = box[0].get(p[c][0][1] - 1) - box[0].get(p[c][0][0] - 1);
            int L = box[1].get(p[a][1][0]) - box[1].get(p[c][1][0] - 1);
            int R = box[0].get(p[b][0][0]) - box[0].get(p[c][0][0] - 1);
            cout << L + R - s - (h[a] + h[b] - h[c] * 2 + 1) << '\n';
        }
    }
} 
