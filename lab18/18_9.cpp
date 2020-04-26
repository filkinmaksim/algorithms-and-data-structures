//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int q;
    cin >> q;
    
    set <pair<int,int> > s;
    map <int,int> m;

    while(q--){
        string st;
        int x;
        cin >> st >> x;
        if (st == "+"){
            s.erase({-m[x],x});
            m[x]++;
            s.insert({-m[x],x});
        } else{
            s.erase({-m[x],x});
            m[x]--;
            if (m[x])
                s.insert({-m[x],x});
        }
        if (s.empty())
            cout << 0 << '\n';
        else
            cout << (*s.begin()).second << '\n';
        
    }

    return 0;
}



