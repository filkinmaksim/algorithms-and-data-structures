//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    set <pair<int,string> > q;
    map <string, int> m;

    string s;
    while (cin >> s){
        if (s[0] == 'A'){
            string name;
            int x;
            cin >> name >> x;
            q.insert({-x,name});
            m[name] = x;
        }
        if (s[0] == 'P'){
            cout << (*q.begin()).second << ' ' << -(*q.begin()).first << '\n';
            q.erase(q.begin());
        }
        if (s[0] == 'C'){
            string name;
            int x;
            cin >> name >> x;
            q.erase({-m[name],name});
            q.insert({-x,name});
            m[name] = x;
            
        }
    }
    

    return 0;
}



