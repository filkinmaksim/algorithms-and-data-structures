#include<bits/stdc++.h>
using namespace std;


int bsearch_leftmost(vector <int> array, int x){
    int l = 0, r = array.size() - 1;
    while (r - l > 1){
        int m = l + ((r - l ) >> 1);
        if (array[m] > x)
            r = m;
        else
            l = m;
    }
    if (array[r] >= x && (array[l] != x || array[r] == x))
        return r;
    if (array[l] >= x)
        return l;
    return -1;
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
        cout << bsearch_leftmost(array,x)  << endl;
    }
}
