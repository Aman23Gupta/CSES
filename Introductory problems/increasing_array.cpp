#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main() {
    cin >> n;
    a.resize(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_so_far = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < max_so_far) {
            ans += max_so_far - a[i];
        } else {
            max_so_far = a[i];
        }
    }

    cout << ans << "\n";
    return 0;
}