#include <bits/stdc++.h>
using namespace std;

bool is_letter(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <='z'));
}

int main() {
    string s;
    set <string> m;
    while (getline(cin, s)){
        if (s[0] == '1')
            break;
        string temp = "";
        int i = 0;
        while (i < s.size()){
            string temp = "";
            while (i < s.size() && is_letter(s[i])){
                if (s[i] >= 'A' && s[i] <= 'Z')
                    temp += s[i] - 'A' + 'a';
                else
                    temp += s[i];
                i++;
            }
            if (temp != "")
                m.insert(temp);
            while (i < s.size() && !is_letter(s[i]))
                i++;
        }
    }
    for (auto v : m)
        cout << v << endl;
}
