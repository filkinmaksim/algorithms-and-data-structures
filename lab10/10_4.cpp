//OnlyVim 23.03.2020
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lint;
typedef long double ld;
//typedef vector <long long> vl;
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
lint powmod(lint x,lint y,lint mod){lint res=1;while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;}return res;}
vector <int> read(int n){vector <int> a(n); for (int i = 0; i < n; i++) cin >> a[i]; return a;}
vector <long long> read_ll(int n){vector <long long> a(n); for (int i = 0; i < n; i++) cin >> a[i]; return a;}


const lint bigmod = 1e9;
typedef vector <long long> biglong;

////////////////// LONG LONG LONG LONG INT v1.0 /////////////
////////////////// begin ////////////////////////////////////
biglong operator + (const biglong &a, const biglong &b){ biglong ans; lint cur = 0; for (int i = 0; i < max(a.size(), b.size()) || cur; i++){ ans.push_back((i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0) + cur); cur = ans[i] / bigmod; ans[i] %= bigmod; }return ans;}
biglong operator * (const biglong &a, const biglong &b){ biglong ans; lint cur = 0; ans.resize(a.size() + b.size()); for (int i = 0; i < a.size(); i++){ for (int j = 0; j < b.size() || cur; j++){ ans[i + j] += a[i] * (j < b.size() ? b[j] : 0) + cur; cur = ans[i + j] / bigmod; ans[i + j] %= bigmod;}} while (ans.size() > 1 && ans.back() == 0) ans.pop_back(); return ans;}
biglong operator - (const biglong &a, const biglong &b){ biglong ans = a; lint cur = 0; for (int i = 0; i < b.size() || cur; i++){ ans[i] -= (i < b.size() ? b[i] : 0) + cur; cur = ans[i] < 0; if (cur) ans[i] += bigmod;} while (ans.size() > 1 && ans.back() == 0) ans.pop_back(); return ans;}
bool operator < (const biglong &a, const biglong &b){ if (a.size() != b.size()) return a.size() < b.size(); for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return a[i] < b[i]; return 0;}
bool operator <= (const biglong &a, const biglong &b){ if (a.size() != b.size()) return a.size() < b.size(); for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return a[i] < b[i]; return 1;}
bool operator > (const biglong &a, const biglong &b){ if (a.size() != b.size()) return a.size() > b.size(); for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return a[i] > b[i]; return 0;}
bool operator >= (const biglong &a, const biglong &b){ if (a.size() != b.size()) return a.size() > b.size(); for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return a[i] > b[i]; return 1;}
bool operator == (const biglong &a, const biglong &b){ if (a.size() != b.size()) return 0; for (int i = 0; i < a.size(); i++) if (a[i] != b[i]) return 0; return 1;}
void readbiglong(biglong &a){ string s; cin >> s; for (int i = s.size(); i > 0; i -= 9){ if (i < 9) a.push_back(atoi(s.substr(0,i).c_str())); else a.push_back(atoi(s.substr(i - 9, 9).c_str())); } while (a.size() > 1 && a.back() == 0) a.pop_back();}
void writebiglong (const biglong &a){ printf("%d",a[a.size() - 1]); for (int i = a.size() - 2; i > -1; i--) printf("%09d", a[i]); printf("\n");}
////////////////// end //////////////////////////////////////

////////////////// fraction v1.0 ////////////////////////////
////////////////// begin ////////////////////////////////////
struct fraction{lint numerator,denominator;};
fraction shorten (const lint &a, const lint &b){ fraction ans;ans.numerator = a; ans.denominator = b; lint nok = __gcd(ans.numerator,ans.denominator);ans.numerator /= nok; ans.denominator /= nok; if (ans.denominator < 0) ans.denominator *= -1, ans.numerator *= -1;return ans;}
fraction operator + (fraction a, fraction b){ return shorten(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);}
fraction operator - (fraction a, fraction b){ return shorten(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);}
fraction operator * (fraction a, fraction b){ return shorten(a.numerator * b.numerator, a.denominator * b.denominator);}
fraction operator / (fraction a, fraction b){ return shorten(a.numerator * b.denominator, a.denominator * b.numerator);}
void writedrop (const fraction &a){ cout << a.numerator; if (a.denominator != 1) cout << "/" << a.denominator;cout << endl;}
////////////////// end //////////////////////////////////////


void solve(){
    biglong a,b;
    readbiglong(a);
    readbiglong(b);
    writebiglong(a * b);
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
