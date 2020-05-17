#include <bits/stdc++.h>

using namespace std;

vector <int> dx = {-1,1,0,0};
vector <int> dy = {0,0,1,-1};
vector <vector <bool> > g; 
int n,m;

void dfs(int x, int y){
    
    g[x][y] = 0;

    for (int i = 0; i < 4; i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if (x1 < 0 || y1 < 0 || x1 == n || y1 == m)
            continue;
        
        if (g[x1][y1])
            dfs(x1,y1);
    }
}

int main(){ 
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    g.resize(n, vector <bool> (m));
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            g[i][j] = (s[j] == '#');
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j]){
                dfs(i,j);
                ans++;
            }
    cout << ans << endl;
}
