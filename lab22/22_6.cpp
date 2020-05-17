#include <bits/stdc++.h>

using namespace std;

vector<vector <int> > g;
vector <int> vis;
vector<int> ans_w;
vector <vector <int> > ans;

void dfs (int v) {
	vis[v] = true;
	for (auto u : g[v])
		if (!vis[u])
			dfs (u);
        
	ans_w.push_back(v);
}


int main(){ 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vis.resize(n);
    g.resize(n);
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
        if (!vis[i]){
            dfs(i);
            ans.push_back(ans_w);
            ans_w.clear();
        }
    

    cout << ans.size() << endl;
    for (auto v : ans){
        cout << v.size() << endl;
        for (auto u : v)
            cout << u + 1 << ' ';
        cout << endl;
    }
}
