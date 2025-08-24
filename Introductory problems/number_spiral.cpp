#include <bits/stdc++.h>
using namespace std;
long long t;

int main() {
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        if (x > y) {
            if (x % 2 == 0) {
                cout << x * x - y + 1 << "\n";
            } else {
                cout << (x - 1) * (x - 1) + y << "\n";
            }
        }
        else {
            if (y % 2 == 0) {
                cout << (y - 1) * (y - 1) + x << "\n";
            } else {
                cout << y * y - x + 1 << "\n";
            }
        }
    }

    return 0;
}