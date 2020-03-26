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
    string s;
    queue <int> q;
    while (cin >> s){
        if (s == "push"){
            int x;
            cin >> x;
            q.push(x);
            cout << "ok\n";
        }
        if (s == "exit"){
            cout << "bye\n";
            break;
        }
        if (s == "clear"){
            q = {};
            cout << "ok\n";
        }
        if (s == "size"){
            cout << (int)q.size() << endl;
        }
        if (s == "front"){
            if (q.empty())
                cout << "error\n";
            else
                cout << (int)q.front() << endl;
        }
        if (s == "pop"){
            if (q.empty())
                cout << "error\n";
            else{
                cout << (int)q.front() << endl;
                q.pop();
            }
        }
    }
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
