//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

vector <pair<int,int> > tree;
vector <int> a;

void build_tree(int v, int tl, int tr){

    if(tl == tr) {
        tree[v] = {a[tl],a[tl]};
        return;
    }

    int mid = tl + ((tr - tl) >> 1);
    
    build_tree(v << 1, tl, mid); 
    build_tree((v << 1) + 1, mid + 1, tr); 

    tree[v] = {max(tree[v << 1].first, tree[(v << 1) + 1].first), min(tree[v << 1].second, tree[(v << 1) + 1].second)};
}

void update_tree(int v, int ind, int val, int tl, int tr){
    
    if (tl == tr){
        tree[v] = {val, val};
        return;
    }

    int mid = tl + ((tr - tl) >> 1);
    
    if (ind <= mid)
        update_tree(v << 1, ind, val, tl, mid); 
    else
        update_tree((v << 1) + 1, ind, val, mid + 1, tr); 
 
    tree[v] = {max(tree[v << 1].first, tree[(v << 1) + 1].first), min(tree[v << 1].second, tree[(v << 1) + 1].second)};
}


pair<int,int> segment_tree(int v, int l, int r, int tl, int tr){

    if (l > r)
        return {-1e9,1e9};

    if (l == tl && r == tr)
        return tree[v];

    int mid = tl + ((tr - tl) >> 1);
    auto v1 = segment_tree(v << 1, l, min(r, mid), tl, mid);
    auto v2 = segment_tree((v << 1) + 1, max(l, mid + 1), r, mid + 1, tr);
    return {max(v1.first, v2.first), min(v1.second, v2.second)};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    n = 100001;
    a.resize(n + 1);
    tree.resize(4 * n,{-1e9,1e9});
    for (long long i = 1; i <= n; i++)
        a[i] = ((i * i) % 12345) + ((i * i * i) % 23456);
    build_tree(1, 1, n);
    cin >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        if (x > 0){
            auto ans = segment_tree(1, x, y, 1, n);
            cout << ans.first - ans.second << endl;
        } else
            update_tree(1, -x, y, 1, n);
        
    }
}
