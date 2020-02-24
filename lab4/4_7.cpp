#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int> mas, int k) {
    int l = 1, r = 1e9;
    while (l < r)
    {
        int m = (l + r) / 2;
        int an = 0;
        for (int i = 0; i < mas.size(); ++i)
            an += mas[i] / m;
        if (an >= k)
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> mas;
    mas.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> mas[i];
    cout << bs(mas, k) << endl;
}
