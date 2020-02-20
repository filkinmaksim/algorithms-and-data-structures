#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int m;
  cin >> m;
  while(m--){
    int x;
    cin >> x;
    int l = 0, r = n - 1;
    while (r - l > 1){
      int m = l + ((r - l) >> 1);
      if (arr[m] >= x)
        r = m;
      else
        l = m;
    }
    if (arr[l] == x || arr[r] == x)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
