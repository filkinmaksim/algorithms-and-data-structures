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


struct Elements{
    int x, y, ind;
};

bool comp(Elements a, Elements b){
    return (a.x != b.x? a.x < b.x : a.ind < b.ind);
}

void QuickSortAlgo(vector <Elements> &a, int l, int r){
    if (l >= r)
        return;
    Elements et = a[r];
    int i = l - 1;
    for (int j = l ; j < r; j++){
        if (comp(a[j], et)){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    int mid = i + 1;
    QuickSortAlgo(a, l, mid - 1);
    QuickSortAlgo(a, mid + 1, r);
}

void QuickSort(vector <Elements> &a){
    QuickSortAlgo(a, 0, a.size() - 1);
}


void solve(){
    int n;
    cin >> n;
    vector <Elements> a(n);
    for (int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        a[i].x = x;
        a[i].y = y;
        a[i].ind = i;
    }
    QuickSort(a);
    for (int i = 0; i < n; i++)
        cout << a[i].x << ' ' << a[i].y << endl;
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
