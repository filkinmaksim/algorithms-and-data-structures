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
    bool ok = false;
    vector <vector <int> > g(n, vector <int> (n));
    while(m--){
        int x,y;
        cin >> x >> y;
        x--;y--;
        g[x][y]++;
        if (g[x][y] > 1)
            ok = true;
    }

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
            
    return 0;
}
