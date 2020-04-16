//OnlyVim 16.04.2020
#include <bits/stdc++.h>

using namespace std;

vector <vector<int> > g;
vector <int> color;
vector <vector<int>> s;
vector <int> ans;

void dfs(int v){
    if(s[color[v]].size())
        ans[v] = s[color[v]].back();
    s[color[v]].push_back(v);
    for (auto u : g[v])
        dfs(u);
    s[color[v]].pop_back();
}

int main(){
	int n,c;
    cin >> n >> c;
    g.resize(n);
    color.resize(n);
    s.resize(c + 1);
    ans.resize(n, -2);
    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        x--;
        g[x].push_back(i + 1);
    }
    for (int i = 0; i < n; i++)
        cin >> color[i];
    
    dfs(0);

    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << endl;

}
