#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int go(int i, int n, vector<int> &a, int sum, int total_sum) {
    if(i == n) {
        return abs(total_sum - 2 * sum);
    }

    // Include the current element
    int include = go(i + 1, n, a, sum + a[i], total_sum); 
    // Exclude the current element
    int exclude = go(i + 1, n, a, sum, total_sum);
    
    return min(include, exclude);
}

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    int total_sum = accumulate(a.begin(), a.end(), 0LL);
    int ans = go(0, n, a, 0, total_sum);
    cout << ans << endl;
    return 0;
}