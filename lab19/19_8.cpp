//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

const int inf=INT_MAX;

vector<long long> a, t;

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = tl+((tr-tl)>>1);
    build(v<<1, tl, tm);
    build((v<<1)+1, tm+1, tr);
    t[v] = t[v<<1]+t[(v<<1)+1];
}

void update(int v, long long data, int index, int tl, int tr) {
    if(tl == tr) {
        t[v] = data;
        a[index] = data;
        return;
    }
    int tm = tl+((tr-tl)>>1);
    if(index <= tm)
        update(v<<1, data, index, tl, tm);
    else
        update((v<<1)+1, data, index, tm+1, tr);
    t[v] = t[v<<1]+t[(v<<1)+1];
}

int find(int v, int tl, int tr, long long x) {
    if(tl == tr) return tl;
    int tm = tl+((tr-tl)>>1);
    if(x < t[v<<1])
        return find(v<<1, tl, tm, x);
    else
        return find((v<<1)+1, tm+1, tr, x-t[v<<1]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, operation;
    long long x, y;
    cin >> n;
    a.resize(n+2);
    t.resize(4*n);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    n++;
    a[n]=inf;
    build(1, 1, n);
    cin >> k;
    while(k--) {
        cin >> operation >> x;
        if(operation == 2)  {
            cin >> y;
            update(1, y, x, 1, n);
        }
        else
            cout << find(1, 1, n, x)-1 << "\n";
    }
    return 0;
}
