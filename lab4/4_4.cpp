#include <bits/stdc++.h>

using namespace std;


int main() {
    int vmax, d, n;
    cin >> vmax >> d >> n;
    vector <pair<double,double>> cords(n);
    for (int i = 0; i < n; i++) {
        string time;
        cin >> cords[i].first >> time;
        double minutes = (time[0] - '0') * 600 + (time[1] - '0') * 60 + (time[3] - '0') * 10 + time[4] - '0';
        cords[i].second = minutes;
    }
    double l = 0, r = cords[n - 1].second;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2, x = 0;
        double time = m;
        for (int i = 0; i < n - 1; i++) {
            time += (cords[i].first - x) / vmax;
            if (time >= cords[i].second)
                time += d;
            x = cords[i].first;
        }
        time += (cords[n - 1].first - x) / vmax;
        if (time <= cords[n - 1].second)
            l = m;
        else
            r = m;
    }
    int time = ceil(l + 2 * cords[n - 1].first / vmax + d * n);
    printf("%d%d:%d%d", time / 600, time / 60 % 10, time % 60 / 10, time % 10);
    return 0;
}
