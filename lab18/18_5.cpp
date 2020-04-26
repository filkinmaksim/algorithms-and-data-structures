//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int n;
    cin >> n;
    multiset <long long> s;
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        s.insert(x);
    }

    long long ans = 0;

    while (s.size() > 1){
        long long x = *s.begin();
        s.erase(s.begin());
        long long y = *s.begin();
        s.erase(s.begin());
        
        s.insert(x + y);
        ans += x + y;
    }


    cout << ans << '\n';
    

    return 0;
}



