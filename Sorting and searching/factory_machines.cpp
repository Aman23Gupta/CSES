#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool sum(int m, int t, vector<int>& a) {
    int res = 0;
    for(int i=0;i<a.size();i++) {
        if(res >= 1e9+7) return true;
        res += m/a[i];
    }

    return res >= t;
}

int32_t main() {
    int n, t; cin >> n >> t;

    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int l = 0, h = 1e18, ans = 1e18+7;

    while(l <= h) {
        int m = l + (h - l)/2LL;
        //cout<<l<<" "<<h<<"\n";
        if(sum(m, t, a)) {
            //cout<<m<<"\n";
            ans = min(ans, m);
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << ans << endl;

    return 0;
}