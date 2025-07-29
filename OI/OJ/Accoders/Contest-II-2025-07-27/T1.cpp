#include <bits/stdc++.h>
using namespace std;
vector<double> dists;
double min_dist = 1e18;
int min_index = -1;
int main() {
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    double X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;

    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;

        double dx = 0, dy = 0;
        if (x < X1)
            dx = X1 - x;
        else if (x > X2)
            dx = x - X2;

        if (y < Y1)
            dy = Y1 - y;
        else if (y > Y2)
            dy = y - Y2;

        double dist = sqrt(dx * dx + dy * dy);
        dists.push_back(dist);

        if (dist < min_dist || (dist == min_dist && i + 1 < min_index)) {
            min_dist = dist;
            min_index = i + 1;
        }
    }

    cout << fixed << setprecision(9);
    for (int i = 0; i < dists.size(); i++) {
        cout << dists[i];
        if (i < dists.size() - 1)
            cout << " ";
    }
    cout << endl;

    cout << min_index - 1 << endl;

    return 0;
}