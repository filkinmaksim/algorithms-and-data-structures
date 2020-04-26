//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

 

typedef long long ll;

const int MOD = 2010;
const int MAXN = 5e4 + 5;
const int K = 12;
 
ll tt[4 * MAXN][K];
int tt_push[4 * MAXN];
int deg[4 * MAXN];
int sh[K][K];
int a[MAXN];
 
void push(int v){
    if(tt_push[v]){
        int v1 = 2 * v + 1, v2 = 2 * v + 2;
        tt_push[v1] = sh[tt_push[v1]][tt_push[v]];
        tt_push[v2] = sh[tt_push[v2]][tt_push[v]];
        deg[v1] = sh[deg[v1]][tt_push[v]];
        deg[v2] = sh[deg[v2]][tt_push[v]];
        tt_push[v] = 0;
    }
}
 
void build(int n){
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < K; j++){
            tt[i][j] = tt[2 * i + 1][j] + tt[2 * i + 2][j];
        }
    }
}
 
void update(int v, int tl, int tr, int l, int r){
    if(l > r) return;
    if(tl == l && tr == r){
        tt_push[v] = sh[tt_push[v]][1];
        deg[v] = sh[deg[v]][1];
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    update(2 * v + 1, tl, tm, l, min(r, tm));
    update(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
    for(int i = 0; i < K; i++){
        tt[v][i] = tt[2 * v + 1][sh[deg[2 * v + 1]][i]] +
                    tt[2 * v + 2][sh[deg[2 * v + 2]][i]];
    }
    deg[v] = 0;
}
 
ll get_sum(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r){
        return tt[v][deg[v]];
    }
    push(v);
    int tm = (tl + tr) >> 1;
    return get_sum(2 * v + 1, tl, tm, l, min(r, tm)) +
            get_sum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            sh[i][j] = i + j;
            while(sh[i][j] >= 12){
                sh[i][j] -= 10;
            }
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 1;
    while(cnt < n) cnt <<= 1;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < n; j++){
            tt[cnt - 1 + j][i] = a[j];
            a[j] = (a[j] * a[j]) % MOD;
        }
    }
    build(cnt);
    int m;
    cin >> m;
    while(m--){
        int op, l, r;
        cin >> op >> l >> r;
        l--; r--;
        if(op == 1)
            update(0, cnt - 1, 2 * cnt - 2, cnt - 1 + l, cnt - 1 + r);
        else
            cout << get_sum(0, cnt - 1, 2 * cnt - 2, cnt - 1 + l, cnt - 1 + r) << "\n";
    }
}
