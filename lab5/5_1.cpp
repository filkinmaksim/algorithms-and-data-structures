    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string s;
        map <string, vector <string> > m;
        while (getline(cin, s)){
            string temp = "";
            int i = 0;
            while (s[i] != ' ')
                temp += s[i], i++;
            i+=3;
            string te = "";
            while (i < s.size()){
                if (s[i] == ','){
                    m[te].push_back(temp);
                    te = "";
                    i+=2;
                } else{
                    te += s[i];
                    i++;
                }
            }
            m[te].push_back(temp);
        }
        cout << m.size() << endl;
        for (auto v : m){
            cout << v.first << " - ";
            for (int i = 0; i < v.second.size() - 1; i++)
                cout << v.second[i] << ", ";
            cout << v.second[v.second.size() - 1] << endl;
        }
    }
