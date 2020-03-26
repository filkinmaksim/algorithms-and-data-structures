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


vector <ll> tree_sum, tree_min;
vector <int> a;

void build_tree(int v, int tl, int tr){
    if (tl == tr){
        tree_sum[v] = a[tl];
        tree_min[v] = a[tl];
        return;
    }
    int mid = tl + ((tr - tl) >> 1);
    build_tree(v << 1, tl, mid);
    build_tree((v << 1) + 1, mid + 1, tr);
    tree_min[v] = min(tree_min[v << 1], tree_min[(v << 1) + 1]);
}

void push(int v){
    if (tree_sum[v]){
        tree_sum[v << 1] += tree_sum[v];
        tree_min[v << 1] += tree_sum[v];
        tree_sum[(v << 1) + 1] += tree_sum[v];
        tree_min[(v << 1) + 1] += tree_sum[v];
        tree_sum[v] = 0;
    }
}

void update_tree(int v, int tl, int tr, int l, int r, int val){
    if (l > r)
        return;
    if (l == tl && tr == r){
        tree_sum[v] += val;
        tree_min[v] += val;
        return;
    }
    push(v);
    int mid = tl + ((tr - tl) >> 1);
    update_tree(v << 1, tl, mid, l, min(r, mid), val);
    update_tree((v << 1) + 1, mid + 1, tr, max(l, mid + 1), r, val);
    tree_min[v] = min(tree_min[v << 1], tree_min[(v << 1) + 1]);
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    a.resize(n);
    tree_sum.resize(4 * n + 5);
    tree_min.resize(4 * n + 5,1e9);
    for (int i = 0; i < n; i++)
        a[i] = (i > 0 ? a[i - 1] : 0) + (s[i] == '(') - (s[i] == ')');
    build_tree(1, 0, n - 1);
    int m;
    cin >> m;
    int bal = a.back();
    while(m--){
        int x;
        cin >> x;
        if (s[x] == '('){
            s[x] = ')';
            update_tree(1, 0, n - 1, x, n - 1, -2);
            bal -= 2;
        } else{
            s[x] = '(';
            update_tree(1, 0, n - 1, x, n - 1, 2);
            bal += 2;
        }
        if (tree_min[1] >= 0 && bal == 0)
            printf("+\n");
        else
            printf("-\n");
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
