//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

vector <long long> tree;
vector <long long> a;
vector <long long> pows;

const int mod = 1e9 + 7;

void build_tree(int v, int tl, int tr){

    if(tl == tr) {
        tree[v] = (a[tl] * pows[tl - 1]) % mod;
        return;
    }

    int mid = tl + ((tr - tl) >> 1);
    
    build_tree(v << 1, tl, mid); 
    build_tree((v << 1) + 1, mid + 1, tr); 

    tree[v] = (tree[v << 1] + tree[(v << 1) + 1]) % mod;
}

void update_tree(int v, int ind, int val, int tl, int tr){
    
    if (tl == tr){
        tree[v] = (val * pows[ind - 1]) % mod;
        return;
    }

    int mid = tl + ((tr - tl) >> 1);
    
    if (ind <= mid)
        update_tree(v << 1, ind, val, tl, mid); 
    else
        update_tree((v << 1) + 1, ind, val, mid + 1, tr); 
 
    tree[v] = (tree[v << 1] + tree[(v << 1) + 1]) % mod;   
}


int segment_tree(int v, int l, int r, int tl, int tr){

    if (l > r)
        return 0;

    if (l == tl && r == tr)
        return tree[v];

    int mid = tl + ((tr - tl) >> 1);
    
    return (segment_tree(v << 1, l, min(r, mid), tl, mid) + segment_tree((v << 1) + 1, max(l, mid + 1), r, mid + 1, tr)) % mod;
}

const int prime = 61;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    string s;
    cin >> n >> m >> s;
    a.resize(n + 1);
    pows.resize(n + 1);
    tree.resize(4 * n);
    
    for (int i = 1; i <= n; i++)
        a[i] = int(s[i - 1] - 'a') + 1;
    pows[0] = 1;
    for (int i = 1; i <= n; i++)
        pows[i] = (pows[i - 1] * prime) % mod;

    build_tree(1, 1, n);

    while(m--){
        string st;
        cin >> st;
        if (st == "?"){
            int i,j,l;
            cin >> i >> j >> l;
            if (i > j)
                swap(i,j);
            if ((segment_tree(1, i, i + l - 1, 1, n) * pows[j - i]) % mod == segment_tree(1, j, j + l - 1, 1, n))
                cout << "+";
            else
                cout << "-";
        } else{
            int x;
            string w;
            cin >> x >> w;
            int y = int(w[0] - 'a') + 1;
            update_tree(1, x, y, 1, n);
        }
    }
}
