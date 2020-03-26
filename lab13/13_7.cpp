//OnlyVim 23.03.2020
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
 
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

class deque{
	struct node{
        int data;
		node *next, *prev;
		node() { prev = next = nullptr; }
		node(int a){
			data = a;
			prev = next = nullptr;
		}
	} *Head, *Tail;

public:
    int sz = 0;
	deque(){ 
        Head = Tail = nullptr; 
    }
	void push_back(int a){
		sz++;
        node *p = new node(a);
		if (Head == nullptr) 
            Head = Tail = p;
		else{
			p->prev = Tail;
			p->next = nullptr;
			Tail->next = p;
			Tail = p;
		}
	}

	void push_front(int a){
		sz++;
        node *p = new node(a);
		if (Head == nullptr) 
            Head = Tail = p;
		else{
			p->next = Head;
			p->prev = nullptr;
			Head->prev = p;
			Head = p;
		}
	}

	int pop_front(){
		sz--;
        node *p = Head;
		int r = Head->data;
		if (Head == Tail) 
            Head = Tail = nullptr;
		else{
			Head = Head->next;
			Head->prev = nullptr;
		}
		delete p;
		return r;
	}

	int pop_back(){
		sz--;
        node *p = Tail;
		int r = Tail->data;
		if (Head == Tail) 
            Head = Tail = nullptr;
		else{
			Tail = Tail->prev;
			Tail->next = nullptr;
		}
		delete p;
		return r;
	}

	int empty() const{ 
        return Head == nullptr; 
    }

	int front() const{ 
        return Head->data; 
    }

	int back() const{ 
        return Tail->data; 
    }
    void clear(){
        Head = Tail = nullptr;
        sz = 0;
    }
};


void solve(){
    string s;
    deque q;
    while (cin >> s){
		
        if (s == "push_back"){
            int b;
            cin >> b;
			q.push_back(b);
            cout << "ok\n";
		}
		if (s == "push_front"){
			int b;
            cin >> b;
            q.push_front(b);
            cout << "ok\n";
		}
		if (s == "pop_front"){
            if (q.empty())
                cout << "error\n";
            else{
			    cout << q.front() << endl;
			    q.pop_front();
            }
		}
		if (s == "pop_back"){
            if (q.empty())
                cout << "error\n";
            else{
                cout << q.back() << endl;
			    q.pop_back();
            }
        }
        if (s == "front"){
            if (q.empty())
                cout << "error\n";
            else{
			    cout << q.front() << endl;
			    //q.pop_front();
            }
		}
		if (s == "back"){
            if (q.empty())
                cout << "error\n";
            else{
                cout << q.back() << endl;
			    //q.pop_back();
            }
        }
        if (s == "size"){
            cout << q.sz << endl;
        }
        if (s == "clear"){
            q.clear();
            cout << "ok\n";
        }
        if (s == "exit"){
            cout << "bye\n";
            break;
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
