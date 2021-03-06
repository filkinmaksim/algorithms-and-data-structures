//OnlyVim 23.03.2020
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <long long> vl;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <vector <long long>> vvl;
typedef vector <pair<int,int> > vii;
typedef vector <pair<long long,long long> > vll;
typedef vector <vector <pair<int,int > > > vvii;
typedef vector <vector <pair<long long,long long > > > vvll;
 
const ld pi = 3.14159265358979323846;
 
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb1(x)                cerr<<#x<<": "<<x<<endl
#define deb2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define all(x) (x).begin(), (x).end()
#define die(x) { cout << (x); exit(0); }
#define endl '\n'
#define files(x) freopen(#x".in", "r", stdin); \
                     freopen(#x".out", "w", stdout)
 
template<class T> void debn(vector <T> a){for (auto v : a)cout << v << ' ';cout << endl;}
template<class T> void debnn(vector <vector <T> > a){for (auto v : a){for (auto w : v)cout << w << ' ';cout << endl;}}
ll powmod(ll x,ll y,ll mod){ll res=1;while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;}return res;}
vector <int> read(int n){vector <int> a(n); for (int i = 0; i < n; i++) cin >> a[i]; return a;}
vector <long long> read_ll(int n){vector <long long> a(n); for (int i = 0; i < n; i++) cin >> a[i]; return a;}



void solve(){
    string a;
    map < char, long long > used;
    cin >> a;
    char ch = 'A';
    for(int i = 0; i <= 37; i++) {
        if(i >= 10) {
            used[ch] = i;
            ch++;
        }
        else {
            used[i + '0'] = i;
        }
    }
    a = '+' + a;
    long long root = 0, mx = -1e18;
    for(int i = 0; i < a.size(); i++)
        mx = max(mx, used[a[i]]);
    long long b[5];
    for(int k = mx + 1; k <= 36; k++) {
        long long p = 1, h = 3;
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] != '+' && a[i] != '=') {
                root = root + used[a[i]] * p;
                p = p * k;
            }
            else{
                b[h] = root;
                h--;
                root = 0;
                p = 1;
            }
        }
        if(b[1] + b[2] == b[3]){
            cout << k << endl;
            return;
        }
    }
    cout << -1 << endl;
}




int main(){
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
