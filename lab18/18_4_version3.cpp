//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    priority_queue <pair<int,string> > q;
    map <string, int> m;
    
    string s;
    while (cin >> s){
        if (s[0] == 'A' || s[0] == 'C'){
            string name;
            int x;
            cin >> name >> x;
            q.push({x,name});
            m[name] = x;
        }
        if (s[0] == 'P'){
            while(m[q.top().second] != q.top().first)
                q.pop();
            cout << q.top().second << ' ' << q.top().first << '\n';
            q.pop();
        }
    }
    

    return 0;
}
