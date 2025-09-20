#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    vector<int> pref(n+1, 0);

    for(int i=0;i<n;i++) {
        pref[i+1] = pref[i] + a[i];
    }
    int ans = pref[n];
    // pref[n] - 2*pref[i] + (left - right) * a[i]
    for(int i=0;i<n;i++) {
        int val = pref[n] - 2 * pref[i] + (2*i - n) * a[i];
        ans = min(ans, val);
    }

    cout<<ans<<"\n";

    return 0;
}