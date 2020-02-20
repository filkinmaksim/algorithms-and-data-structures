#include<bits/stdc++.h>
using namespace std;

int decode_bin(string s){
  int ans = 0;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == '1')
      ans += (1 << i);
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  string st = "";
  while (n){
    st += char((n % 2)) + '0';
    n >>= 1;
  }
  int ans = n;
  for (int i = 0; i < st.size(); i++){
    char temp = st[0];
    for (int i = 0; i < st.size() - 1; i++)
      st[i] = st[i + 1];
    st[st.size() - 1] = temp;
    ans = max(ans,decode_bin(st));
  }
  cout << ans << endl;
}
