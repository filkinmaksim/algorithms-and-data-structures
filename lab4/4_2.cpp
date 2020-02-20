#include <bits/stdc++.h>

using namespace std;
int main(){
    int w, h, n;
    cin >> w >> h >> n;
    int l = 0, r = max(h, n)*(w-1), g = min(h, n);
    while (l < r){
        int m = (l + r)/2;
        if( (m/h)+(m/n) < w-1)
            l = m + 1;
        else 
            r = m;
    }
    cout << l + g;
}
