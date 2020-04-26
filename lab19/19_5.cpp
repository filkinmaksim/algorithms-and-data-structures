//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

vector <int> tree;
vector <int> a;

void build_tree(int v, int tl, int tr){

    if(tl == tr) {
        tree[v] = a[tl];
        return;
    }

    int mid = tl + ((tr - tl) >> 1);
    
    build_tree(v << 1, tl, mid); 
    build_tree((v << 1) + 1, mid + 1, tr); 

    tree[v] = (tree[v << 1] == tree[(v << 1) + 1] ? tree[v << 1] : 0);
}

void update_tree(int v, int ind, int val, int tl, int tr){
    
    if (tl == tr){
        tree[v] = val;
        return;
    }

    int mid = tl + ((tr - tl) >> 1);
    
    if (ind <= mid)
        update_tree(v << 1, ind, val, tl, mid); 
    else
        update_tree((v << 1) + 1, ind, val, mid + 1, tr); 
 
    tree[v] = (tree[v << 1] == tree[(v << 1) + 1] ? tree[v << 1] : 0);
}


int segment_tree(int v, int l, int r, int tl, int tr){

    if (l > r)
        return 0;

    if (l == tl && r == tr)
        return tree[v];

    int mid = tl + ((tr - tl) >> 1);
    if (r <= mid)
        return segment_tree(v << 1, l, min(r, mid), tl, mid);
    if (l >= mid + 1)
        return segment_tree((v << 1) + 1, max(l, mid + 1), r, mid + 1, tr);
    
    int v1 = segment_tree(v << 1, l, min(r, mid), tl, mid);
    return (v1 == segment_tree((v << 1) + 1, max(l, mid + 1), r, mid + 1, tr) ? v1 : 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n;
    a.resize(n + 1);
    tree.resize(4 * n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build_tree(1, 1, n);
    cin >> m;
    while(m--){
        string zap;
        int x,y;
        cin >> zap >> x >> y;
        if (zap[0] == '1')
            cout << (segment_tree(1, x, y, 1, n) == 0 ? "wins" : "draw") << '\n';
        else
            update_tree(1, x, y, 1, n);
        
    }
}
