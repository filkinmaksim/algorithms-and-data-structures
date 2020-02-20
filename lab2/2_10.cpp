#include<bits/stdc++.h>
using namespace std;


int bsearch(vector <int> & array, int x, int l, int r){
    if (r - l > 1){
        if (array[r] == x || array[l] == x)
            return 1;
        return 0;
    }
    int m = l + ((r - l) >> 1);
    if (array[m] > x)
        bsearch(array, x, m, r);
    else
        bsearch(array, x, l, m);
}

int main(){
    int n;
    cin >> n;
    vector <int> array(n);
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        if (bsearch(array,x, 0, n - 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
