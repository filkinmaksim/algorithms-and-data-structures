//OnlyVim 20.04.2020
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int V,L,R,nL,nR;
} n[1001];

int nCk[1001][1001], S, M = 1000003;

void add(int &root, int val){
    if (root==-1){
        n[root = S++] = (Node){ val,-1,-1,0,0 };   
    } else {
        Node &r = n[root];
        if (val < r.V)              
            add(r.L, val), r.nL++;  
        else
            add(r.R, val), r.nR++;  
    }
}

long long f(int root){
    if (root==-1) 
        return 1;
    Node &r = n[root];
    long long ret = nCk[r.nL + r.nR][r.nL]; 
    ret = ret * f(r.L) % M;     
    ret = ret * f(r.R) % M;     
    return ret;
}

int main(){
    nCk[0][0] = 1;
    for (int i=1; i<1001; i++){
        nCk[i][0] = 1;
        for (int j=1; j<1001; j++)
            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % M; 
    }
    int T;
    cin >> T;
    while (T--){
        int n,t,root = -1; S = 1;
        cin >> n >> t;
        for (int i=0; i<n; i++) {
            int val;
            cin >> val; 
            add(root,val);
        }
        cout << int( f(root) * nCk[t][n] % M ) << endl;
    }
}
