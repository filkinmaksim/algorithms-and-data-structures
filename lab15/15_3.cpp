//OnlyVim 13.04.2020
#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > g;
vector <int> color;
vector <set <int>> s;
vector <int> ans;

void dfs(int v){
    s[v].insert(color[v]);
    for (auto u : g[v]){
        dfs(u);
        if (s[v].size() < s[u].size())
            s[v].swap(s[u]);
        s[v].insert(s[u].begin(),s[u].end());
        s[u].clear();
    }
    ans[v] = s[v].size();
}

int main(){
    int n;
    cin >> n;
    int start = -1;
    s.resize(n);
    g.resize(n);
    color.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++){
        int p;
        cin >> p >> color[i];
        p--;
        if (p == -1)
            start = i;
        else
            g[p].push_back(i);
    }

    dfs(start);

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
