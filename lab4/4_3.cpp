#include <bits/stdc++.h>

using namespace std;

vector <int> arr;

int check_fun(int m){
    int count = 1, temp = arr[0];
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] - temp < m)
            continue;
        temp = arr[i];
        count++;
    }
    return count;
}

int main(){
    int n,c;
    cin >> n >> c;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    int ans = 0;
    int r = arr[arr.size() - 1], l = 0;
    while(l < r){
        int m = (l + r + 1) >> 1;
        if (check_fun(m) >= c){
            l = m;
            ans = m;
        } else
            r = m - 1;
    }
    cout << ans << endl;
}
