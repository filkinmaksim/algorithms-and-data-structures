//OnlyVim 16.04.2020
#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> a[50005],top;
bool used[50005];
int last[50005][5];
int x,y,t;
int ans[50005];

void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < a[v].size(); ++i)
		if(!used[a[v][i]])
			dfs(a[v][i]);
	top.push_back(v);
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		--x, --y;
		a[y].push_back(x);
	}
	cin >> k;
	for(int i = 0; i < k; ++i){
		cin >> t >> x;
		--t, --x;
		last[x][t] = i + 1;
	}
	for(int i = 0; i < n; ++i)
		if(!used[i])
			dfs(i);

	for(int i = 0; i < n; ++i){
		int v = top[i];
		for(int j = 0; j < a[v].size(); ++j)
			last[v][3] = max(last[v][3], last[a[v][j]][3]);
		ans[v] |= (last[v][0] > last[v][1]);
		for(int j = 0; j < a[v].size(); ++j)
			ans[v] |= (ans[a[v][j]] && (max(last[a[v][j]][2],last[a[v][j]][3]) > last[a[v][j]][4]));
	}
	for(int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
