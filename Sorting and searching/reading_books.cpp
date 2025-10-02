#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0, m = 0;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        sum += x;
        m = max(m, x);
    }

    cout << max(sum, 2*m) << endl;

    return 0;
}