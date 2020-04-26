//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    priority_queue <pair<int,string> > q;

    string s;
    while (cin >> s){
        if (s[0] == 'A'){
            string name;
            int x;
            cin >> name >> x;
            q.push({x,name});
        }
        if (s[0] == 'P'){
            cout << q.top().second << ' ' << q.top().first << '\n';
            q.pop();
        }
        if (s[0] == 'C'){
            string name;
            int x;
            cin >> name >> x;
            vector <pair<int, string>> a;
            do{
                auto v = q.top();
                q.pop();
                if (v.second == name)
                    break;
                a.push_back(v);
            }while(1);

            q.push({x,name});
            for (auto v : a)
                q.push(v);
        }
    }
    

    return 0;
}
