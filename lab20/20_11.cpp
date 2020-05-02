//OnlyVim 03.05.2020
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector <vector <int> > g(n, vector <int>(n));
    
    while(m--){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x][y]++;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << g[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
