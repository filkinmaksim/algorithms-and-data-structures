//OnlyVim 20.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    int x.pre;
    int l = -2147483648, r = 2147483647;
    cin >> pre;
    bool ok = 1;
    while(cin >> x){
        if (x > r || x < l)
            ok = 0;
        if (pre > x)
            r = pre;
        else
            l = pre;
        pre = x;
    }
    cout << (ok ? "YES" : "NO") << endl;
}
