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
void debnn(vvi a){for (auto v : a){for (auto w : v)cout << w << ' ';cout << endl;}}
ll powmod(ll x,ll y,ll mod){ll res=1;while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;}return res;}
vector <int> read(int n){vector <int> a(n); for (int i = 0; i < n; i++) cin >> a[i]; return a;}
vector <long long> read_ll(int n){vector <long long> a(n); for (int i = 0; i < n; i++) cin >> a[i]; return a;}



void QuickSortAlgo(vector <int> &a, int l, int r){
    if (l >= r)
        return;
    int et = a[r];
    int i = l - 1;
    for (int j = l ; j < r; j++){
        if (a[j] < et){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    int mid = i + 1;
    QuickSortAlgo(a, l, mid - 1);
    QuickSortAlgo(a, mid + 1, r);
}

void QuickSort(vector <int> &a){
    QuickSortAlgo(a, 0, a.size() - 1);
}

vector <int> tree;
const int max_a = 1000000;

void inc(int i, int d){
    while(i < max_a){
        tree[i] += d;
        i = (i + 1) | i;
    }
}

int sum(int i){
    int ans = 0;
    while (i >= 0){
        ans += tree[i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}

void solve(int n){
    vi a = read(n);
    vi b = a;
    sort(a.begin(),a.end());
    unordered_map <int,int> m;
    for (int i = 0; i < n; i++)
        m[a[i]] = i;
    int ind = 0;
    for (int i = 0; i < n; i++)
        inc(i,1);
    long long ans = 0;
    for (int i = 0; i < n; i++){
        inc(m[b[i]], - 1);
        ans += sum(m[b[i]]);
    }
    cout << ans << endl;
}   


int main(){
    fast;
    int t = 1;
    tree.resize(max_a);
    //cin >> t;
    while(cin >> t){
        if (t == 0)
            break;
        solve(t);
    }
    return 0;
}
