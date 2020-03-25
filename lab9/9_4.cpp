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


vi a;
int n;
int gotSum;
int dp[2][701][(1 << 14)];

int rec(int who = 0, int got = 0, int mask = 0){
    if (mask == (1 << 2 * n) - 1)
        return got;
    if (dp[who][got][mask] >= 0)
        return dp[who][got][mask];
    int newWho = (gotSum - got > got ? 0 : gotSum - got < got ? 1 : who);
    int ans;
    if (newWho == 0) {
        ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (((mask >> i) & 1) == 1)
                continue;
            mask |= 1 << i;
            gotSum += a[i];
            got += a[i];
            int cur = 1e9;
            for (int j = 0; j < 2 * n; j++) {
                if (((mask >> j) & 1) == 1) 
                    continue;
                mask |= 1 << j;
                gotSum += a[j];
                cur = min(cur, rec(newWho, got, mask));
                mask &= ~(1 << j);
                gotSum -= a[j];
            }
            ans = max(ans, cur);
            mask &= ~(1 << i);
            gotSum -= a[i];
            got -= a[i];
        }
    } else {
        ans = 1e9;
        for (int i = 0; i < 2 * n; i++) {
            if (((mask >> i) & 1) == 1)
                continue;
            mask |= 1 << i;
            gotSum += a[i];
            int cur = 0;
            for (int j = 0; j < 2 * n; j++) {
                if (((mask >> j) & 1) == 1)
                    continue;
                mask |= 1 << j;
                gotSum += a[j];
                got += a[j];
                cur = max(cur, rec(newWho, got, mask));
                mask &= ~(1 << j);
                gotSum -= a[j];
                got -= a[j];
            }
            ans = min(ans, cur);
            mask &= ~(1 << i);
            gotSum -= a[i];
        }
    }
    return dp[who][got][mask] = ans;
}

int main(){
    fast;
    cin >> n;
    a = read(2 * n);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 701; j++)
            for (int k = 0; k < (1 << 14); k++)
                dp[i][j][k] = -1;
    cout << rec() << endl;
    return 0;
}
