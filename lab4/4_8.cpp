#include <bits/stdc++.h>
using namespace std;

vector <int> a,b,resa;

bool check(int m){
    multiset<pair<int, int> > q;
    int w=0;
    for(int i = 0; i < b.size(); i++)
        q.insert({b[i], b[i]});
    q.insert({INT_MAX, INT_MAX});
    for(int i = resa.size() - 1; i >= 0; i--){
        int y = m - resa[i];
        auto x = q.begin();
        if(y < (x -> first)){
            w++;
            break;
        }
        auto it = q.lower_bound({y, -1});
        int z = it -> first;
        if(z > y)
            it--;
        int val = it -> first, t = it -> second;
        q.erase(it);
        q.insert({val + t, t});
    }
    return (w == 0);
}

int main() {
    int n, na;
    cin >> n >> na;
    multiset<pair<int, int> > s;
    a.resize(na);
    resa.resize(n);
    for(int i = 0; i < na; i++){
        cin >> a[i];
        s.insert({a[i], a[i]});
    }

    for(int i = 0; i < n; i++){
        auto it=s.begin();
        int val = it -> first, t = it -> second;
        s.erase(it);
        s.insert({val+t, t});
        resa[i]=val;
    }

    int nb;
    cin >> nb;
    b.resize(nb);
    for(int i = 0; i < nb; i++)
        cin >> b[i];
    long long l = resa[n-1], r = 10000100;
    while(l < r){
        int m=(l + r) / 2;
        if(check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}
