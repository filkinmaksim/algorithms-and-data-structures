//OnlyVim 01.04.2020
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

int a[2010][2010];
int m,n;
pair <int,int> start;

void bfs(int x, int y, int kol){
    if (x == start.first && y == start.second && kol != 0) 
        return;
    if (a[x][y] <= kol && a[x][y] != 0 || a[x][y] == -1) 
        return;
    a[x][y] = kol;
    if (x + 1 < n) 
        bfs(x+1,y,kol+1);
    if (x - 1 > -1) 
        bfs(x-1,y,kol+1);
    if (y + 1 < m) 
        bfs(x,y+1,kol+1);
    if (y - 1 > -1) 
        bfs(x,y-1,kol+1);
}

void solve(){
    cin >> n >> m;
    string s;
    getline(cin,s);
    for (int i = 0; i < n; i++){
        getline(cin,s);;
        for (int j = 0; j < m; j++)
            if (s[j] == '+') 
                start = make_pair(i,j);
            else 
                if (s[j] == ' ') 
                    a[i][j] = 0;
                else 
                    a[i][j] = -1;
    }
    bfs(start.first,start.second,0);
    pair<int,int> finish = make_pair(-1,-1);
    for (int i = 0; i < n; i++){
        if (a[i][0] > 0){
            if (finish.first == -1)
                finish = make_pair(i,0);
            else 
                if (a[finish.first][finish.second] > a[i][0]) 
                    finish = make_pair(i,0);
        }
        if (a[i][m-1] > 0){
            if (finish.first == -1)
                finish = make_pair(i,m-1);
            else 
                if (a[finish.first][finish.second] > a[i][m-1]) 
                    finish = make_pair(i,m-1);
        }
    }
    for (int i = 0; i < m; i++){
        if (a[0][i] > 0){
            if (finish.first == -1)
                finish = make_pair(i,0);
            else 
                if (a[finish.first][finish.second] > a[0][i]) 
                    finish = make_pair(0,i);
        }
        if (a[n-1][i] > 0){
            if (finish.first == -1)
                finish = make_pair(n-1,i);
            else 
                if (a[finish.first][finish.second] > a[n-1][i]) 
                    finish = make_pair(n-1,i);
        }
    }
    int i = finish.first, j = finish.second;
    if (start.first == 0 || start.first == n - 1 || start.second == 0 || start.second == m-1){
        cout << 0 << endl;
        cout << endl;
        return;
    }
    if (i == -1){ 
        cout << -1 << endl;
        return;
    }
    cout << a[i][j] << endl;
    s = "";
    while (i != start.first || j != start.second){
        if (i + 1 < n && a[i][j] - 1 == a[i+1][j] && a[i+1][j] != -1) 
            i++,s+='n';
        if (i - 1 > -1 && a[i][j] - 1 == a[i-1][j] && a[i-1][j] != -1) 
            i--,s+='s';
        if (j + 1 < m && a[i][j] - 1 == a[i][j+1] && a[i][j+1] != -1) 
            j++,s+='w';
        if (j - 1 > -1 && a[i][j] - 1 == a[i][j-1] && a[i][j-1] != -1) 
            j--,s+='e';
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
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
