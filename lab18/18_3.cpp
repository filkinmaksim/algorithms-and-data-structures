//OnlyVim 21.04.2020
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool ok = 1;
    for (int i = 0; i < n && ok; i++){
        if (i * 2 + 1 < n && a[i] > a[i * 2 + 1])
            ok = 0;
        if (i * 2 + 2 < n && a[i] > a[i * 2 + 2])
            ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
}
