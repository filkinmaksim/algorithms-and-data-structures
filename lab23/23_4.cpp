#include <bits/stdc++.h>

using namespace std;


vector <int> dx = {0,0,-1,1};
vector <int> dy = {1,-1,0,0};
vector <vector <int> > g,vis;
vector <vector <char> > ans;
pair<int,int> s,f;
int n;


void bfs(){
    queue <pair<int,int> > q;
    q.push(s);
    vis[s.first][s.second] = 1;
    while(!q.empty()){

        auto v = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int x = v.first + dx[i];
            int y = v.second + dy[i];
            
            if (x < 0 || y < 0 || x == n || y == n || vis[x][y])
                continue;
            
            g[x][y] = g[v.first][v.second] + 1;
            vis[x][y] = 1;
            q.push({x,y});
    
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n, vector <int> (n));
    vis.resize(n, vector <int>(n));
    ans.resize(n, vector <char>(n,'.'));
    for (int i = 0; i < n; i++){
        string st;
        cin >> st;
        for (int j = 0; j < n; j++){
            if (st[j] == '@')
                s = {i,j}, ans[i][j] = st[j];
            if (st[j] == 'X')
                f = {i,j};
            if (st[j] == 'O')
                vis[i][j] = 1, ans[i][j] = st[j];
        }
    }

    bfs();

    if (g[f.first][f.second]){
        cout << "Y\n";
        int x = f.first, y = f.second;
        while (x != s.first || y != s.second){
            ans[x][y] = '+';
            for (int i = 0; i < 4; i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (x1 < 0 || y1 < 0 || x1 == n || y1 == n || ans[x1][y1] == 'O')
                    continue;
                if (g[x1][y1] + 1 == g[x][y]){
                    x = x1;
                    y = y1;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                cout << ans[i][j];
            cout << '\n';
        }       
    } else{
        cout << "N\n";
    }
       
}
