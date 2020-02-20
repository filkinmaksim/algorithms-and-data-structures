#include <iostream>

using namespace std;

int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    long long l = 0, r = w * n;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (n <= (m / w) * (m / h)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << endl;
    return 0;
}
