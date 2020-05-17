#include <bits/stdc++.h>

using namespace std;

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;

void dfs1(int v) {
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i)
		if (!used[g[v][i]])
			dfs1(g[v][i]);
	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	component.push_back(v);
	for (size_t i = 0; i<gr[v].size(); ++i)
		if (!used[gr[v][i]])
			dfs2(gr[v][i]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int> > components;
	int n, m;
    cin >> n >> m;
	vector<pair<int, int> > reb(m);
	vector<int> num(n);
	gr.resize(n);
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
        cin >> a >> b;
		a--;
		b--;
		reb[i] = {a, b};
		g[a].push_back(b);
		gr[b].push_back(a);
	}

	used.assign(n, false);
	for (int i = 0; i<n; ++i)
		if (!used[i])
			dfs1(i);
	used.assign(n, false);
    vector <int> ans(n);
    int ans_w = 0;
	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (!used[v]) {
			dfs2(v);
			for (auto x : component)
                ans[x] = ans_w + 1;
            ans_w++;
            component.clear();
		}
	}
	cout << ans_w << endl;
    for (auto x : ans)
        cout << x << ' ';
}
