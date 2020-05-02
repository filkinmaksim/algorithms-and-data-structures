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
    map <int,int> a,b;
    while(m--){
        int x,y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
    }


    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ' << a[i] << endl; 
        
    return 0;
}
