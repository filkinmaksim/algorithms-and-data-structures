#include <bits/stdc++.h>

using namespace std;

int SHIFT = 20;

int main(){
    long long R, L, B;
    cin >> R >> L >> B;
    vector<long long> X(R);
    for (int i = 0; i < R; i++)
        cin >> X[i];

    vector<long long> run_sum = {0};
    for (auto x : X) {
        run_sum.push_back(run_sum.back() + x);
    }

    vector<long long> X_nondup = X;
    for (long long i = 0; i != R; ++i) {
        X_nondup[i] <<= SHIFT;
        X_nondup[i] += i;
    }

    long long best = 0;

    for (long long i = 0; i != R; ++i) {
        auto center = X_nondup[i];
        long long low = -1;
        long long high = L << SHIFT;
        long long curr;
        while (low + 1 < high) {
            long long mid = (low + high) / 2;
            auto x = distance(X_nondup.begin(), lower_bound(X_nondup.begin(), X_nondup.end(), center - mid)); 
            auto y = distance(X_nondup.begin(), upper_bound(X_nondup.begin(), X_nondup.end(), center + mid)) - 1;
            auto cost = X[i] * (i - x) - (run_sum[i] - run_sum[x]) + (run_sum[y + 1] - run_sum[i + 1]) - X[i] * (y - i);
            if (cost > B)
                high = mid;
            else
                curr = y - x + 1, low = mid;
        }

        best = max(best, curr);
    }

    cout << best << "\n";
}
