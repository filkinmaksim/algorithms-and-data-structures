//OnlyVim 26.04.2020
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    vector<int> a;
    cin >> n >> k;
    a.resize(n);
    for(auto &i: a)
        cin >> i;
    long long ans=0;
    int left=0, prevk=0;
    bool f=0;
    for(int i=0; i<n; i++) {
        if(a[i]>k) {
            left=i+1;
            f=0;
        }
        else if(a[i]==k) {
            ans+=i-left+1;
            prevk=i;
            f=1;
        }
        else if(a[i]<k && f) {
            ans+=prevk-left+1;
        }
    }
    cout << ans << "\n";
    return 0;
}
