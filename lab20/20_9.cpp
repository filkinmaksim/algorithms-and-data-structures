//OnlyVim 03.05.2020
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    vector <vector <int> > g(n);

    for (int i = 0; i < n; i++)
        for (int j = 0, x; j < n; j++){
            cin >> x;
            if (x)
                g[i].push_back(j);
        }


    for (int i = 0; i < n; i++)
        cout << g[i].size() << ' ';
    return 0;
}
