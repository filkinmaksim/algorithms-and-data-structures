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


const int nmax = 3001;

struct TLong {
	int num[nmax] = { 0 };
	char sign;
	int len;
};

void read(TLong &a) {
	string s;
	cin >> s;
	if (s[0] == '+' || s[0] == '-') {
		a.sign = s[0];
		s.erase(0, 1);
	}
	else
		a.sign = '+';
	for (int i = 0; i < s.size(); i++)
		a.num[nmax - s.size() + i] = int(s[i] - '0');
	a.len = s.size();
}

int comp_abs(TLong a, TLong b) {
	if (a.len > b.len) return 1;
	if (a.len < b.len) return -1;
	for (int i = nmax - a.len; i < nmax; i++) {
		if (a.num[i] > b.num[i]) return 1;
		if (a.num[i] < b.num[i]) return -1;
	}
	return 0;
}

int length(TLong &a) {
	int i = 0;
	while (i < nmax - 1 && a.num[i] == 0) i++;
	if (i == nmax - 1 && a.num[nmax - 1] == 0) a.sign = '+';
	return nmax - i;
}

void add_abs(TLong a, TLong b, TLong &rez) {
	int p = 0;
	for (int i = nmax - 1; i >= 0; i--) {
		rez.num[i] = (a.num[i] + b.num[i] + p) % 10;
		p = (a.num[i] + b.num[i] + p) / 10;
	}
}

void sub_abs(TLong a, TLong b, TLong &rez) {
	for (int i = nmax - 1; i > -1; i--) {
		if (a.num[i] < b.num[i]) {
			a.num[i] += 10;
			a.num[i - 1] -= 1;
		}
		rez.num[i] = a.num[i] - b.num[i];
	}
}


void sub(TLong a, TLong b, TLong &rez) {
	if (a.sign != b.sign) {
		b.sign = a.sign;
		add_abs(a, b, rez);
		rez.sign = a.sign;
	}
	else {
		if (comp_abs(a, b)>-1) {
			sub_abs(a, b, rez);
			rez.sign = a.sign;
		}
		else {
			sub_abs(b, a, rez);
			if (a.sign == '-') rez.sign = '+';
			else rez.sign = '-';
		}
	}
	rez.len = length(rez);
}

void div(TLong a, TLong b, TLong & res, TLong & ost){
	memset(res.num, 0, sizeof(res.num));
	memset(ost.num, 0, sizeof(ost.num));
	ost.len = 1;
	for (int i = nmax - a.len; i<nmax; i++){
		for (int j = nmax-ost.len-2; j< nmax - 1; j++)
			ost.num[j] = ost.num[j + 1];
		ost.num[nmax - 1] = a.num[i];
		ost.len = length(ost);
		int count = 0;
		while (comp_abs(ost, b) >=0){
			sub_abs(ost, b, ost);
			ost.len = length(ost);
			count++;
		}
		res.num[i] = count;
	}
	res.len = length(res);
	ost.len = length(ost);
	if (a.sign == b.sign) res.sign = '+';
	else res.sign = '-';
	ost.sign = a.sign;
}

void mu(TLong a, long long b, TLong & res){
	long long p = 0, s = 0;
	memset(res.num, 0, sizeof(res.num));
	for (int j = nmax - 1; j >= nmax - a.len - 1; j--){
		s = a.num[j] * b + p;
		res.num[j] = s % 10;
		p = s / 10;
	}
	if (a.sign == '+' && b >= 0) res.sign = '+';
	else res.sign = '-';
	res.len = length(res);
}

void vac(long long n, TLong & res){
	res.sign = '+';
	memset(res.num, 0, sizeof(res.num));
	res.num[nmax - 1] = 1;
	res.len = 1;
	for (long long i = 2; i <= n; i++){
		mu(res, i, res);
		res.len = length(res);
	}
}

void write(TLong a){
	if (a.sign == '-') cout << '-';
	for (int i = nmax - a.len; i < nmax; i++)
		cout << a.num[i];
}

void mul(TLong a, TLong b, TLong & res){
	long long p = 0, s = 0;
	memset(res.num, 0, sizeof(res.num));
	for (int i = nmax - 1; i >= nmax - b.len - 1; i--){
		for (int j = nmax - 1; j >= nmax - a.len - 1; j--){
			s = a.num[j] * b.num[i] + p + res.num[i + j - nmax + 1];
			res.num[i + j - nmax + 1] = s % 10;
			p = s / 10;
		}
	}
	if (a.sign == b.sign) res.sign = '+';
	else res.sign = '-';
	res.len = length(res);
}

void w(TLong a, string & s) {
	for (int i = nmax -1; i >= nmax - a.len; i--)
		s+=(char(a.num[i])+'0');
}


void solve(){
    TLong a, b, res, ost;
	string s = "";
	read(a);
	read(b);
	while (comp_abs(a, b) > -1){
		div(a, b, a, ost);
		if (ost.len > 1){
			s += ']';
			w(ost, s);
			s += '[';
		}
		else w(ost, s);
	}
	if (a.len > 1){
		s += ']';
		w(a, s);
		s += '[';
	}
	else 
        w(a, s);
	for (int i = s.size()-1; i>-1; i--)
		cout << s[i];
	cout << endl;
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
