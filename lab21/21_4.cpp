#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

vector <vector <int> > g;
vector <bool> vis;
int f,d,ans = 0;

void dfs(int v, int gl = 0){
    if (gl >= d)
        return;
    vis[v] = 1;
    for (auto u : g[v])
        if (!vis[u]){
            if (u == f)
                ans++;
            else
                dfs(u, gl + 1);
        }
    vis[v] = 0;
}

int main(){
    int n,m,s;

    cin >> n >> m >> s >> f >> d;
    s--;
    f--;
    g.resize(n);
    vis.resize(n);
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        
    }
    dfs(s);
    cout << ans << endl;
}
