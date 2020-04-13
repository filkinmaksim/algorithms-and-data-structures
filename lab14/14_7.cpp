//OnlyVim 13.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <vector<int> > a(2005, vector <int> (2005));
    int q = 0;
    while(n--){
        q++;
        int x,y,h,w;
        cin >> x >> y >> w >> h;
        for (int j = x; j < x + w; j++)
            for (int i = y; i < y + h; i++)
                a[j][i] = q;
    }
    int ans = 0;
    set <int> s;
    for (int i = 0; i < 2005; i++)
        for (int j = 0; j < 2005; j++)
            if (s.count(a[i][j]) == 0){
                ans++;
                s.insert(a[i][j]);
            }
    cout << ans - 1 << endl;
}
