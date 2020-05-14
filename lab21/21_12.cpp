#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

int ans, n = 8;
vector <int> a,b;
 
bool check(int x) { 
	if (b[x] < 0)  
        return 0;
    
    
    for (int i = 0; i < n && b[i] >= 0; i++){           
        if (i == x) 
            continue;
        if (b[x] == b[i] || x + b[x] == i + b[i] || x - b[x] == i - b[i]) 
            return 0;
    }  

    return 1; 
}

 
void rec(int i){
    if (i > n - 1) 
        return;
    
    for (int j = 0; j < n; j++){ 
        b[i] = j;
        if (check(i)){              
            if (i == n - 1){
                int temp = 0;
                for (int i = 0; i < n; i++) 
                    temp += (a[i] != b[i]);
                ans = min(ans, temp);
            }
            else 
                rec(i + 1);
        }
        b[i] = -1 ;  
    } 
    
}
 
int main(){
    int t;
    cin >> t;
    a.resize(n);
    while(t--){
      ans = n + 1;
      b = vector <int> (n, - 1);
      for (int i = 0; i < n; i++){   
          cin >> a[i];  
          a[i]--;    
      }
      rec(0);    
      cout << ans;
    }   
    
    return 0;
}
