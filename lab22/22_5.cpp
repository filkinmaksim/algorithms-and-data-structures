#include <bits/stdc++.h>

using namespace std;

vector<vector <int> > g;
vector <int> vis,vis2;
vector<int> ans;

bool ok = true;

void dfs (int v) {
	vis[v] = true;
    vis2[v] = true;
	for (auto u : g[v])
		if (!vis[u])
			dfs (u);
        else{
            if (vis2[u])
                ok = false;
        }
        
    vis2[v] = false;
	ans.push_back(v);
}


int main(){ 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vis.resize(n);
    vis2.resize(n);
    g.resize(n);
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
    }

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);
    
    reverse(ans.begin(),ans.end());

    if (!ok){
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
}
