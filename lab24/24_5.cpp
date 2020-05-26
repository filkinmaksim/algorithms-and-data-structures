#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<int> way (n, 1e9);
    vector<vector<pair<int, int>>> adj (n);
    vector<int> visited (n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            if (x != -1)
                adj[i].push_back(make_pair(j, x));
        }
    priority_queue<vector<int>> q;
    way[s] = 0;
    q.push({0, s});
    while (!q.empty()){
        int a = q.top()[1];
        q.pop();
        if (visited[a])
            continue;
        visited[a] = 1;
        for (auto u : adj[a]){
            int b = u.first, add = u.second;
            if (way[b] > way[a] + add){
                way[b] = min(way[a] + add, way[b]);
                q.push({-way[b], b});
            }
        }
    }
    if (way[f] == 1e9)
        cout << -1 << endl;
    else
        cout << way[f] << endl;
    
}
