#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

vector <vector <int> > g;
vector <bool> vis;
set <pair<int,int> > s;
void dfs(int v = 0, int pre = 0){
    vis[v] = 1;
    for (auto u : g[v])
        if (s.find({u,v}) == s.end())
            continue;
        
        else if (!vis[u])
            dfs(u, v);
        else{
            if (u == pre)
                continue;
            s.erase({u,v});
            s.erase({v,u});
        }
    vis[v] = 0;
}

int main(){
    int n,m;

    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
        s.insert({x,y});
        s.insert({y,x});
    }
    dfs();
    for (int i = 0; i < n; i++){
        for (auto v : g[i])
            if (s.find({i,v}) != s.end()){
                cout << i + 1 << ' ' << v + 1 << endl;
                s.erase({i,v});
                s.erase({v,i});
            }
    }
}
