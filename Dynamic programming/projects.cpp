#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    }

    sort(a.begin(), a.end());

    vector<int> dp(n, 0);

    for(int i=n-1; i>=0; i--) {
        pair<int,pair<int,int>> findVal = {a[i].second.first, {INT_MAX,INT_MAX}};
        auto it = upper_bound(a.begin(), a.end(), findVal);

        if(it != a.end()) {
            int j = it - a.begin();
            dp[i] = dp[j] + a[i].second.second;
        }
        else {
            dp[i] = a[i].second.second;
        }

        if(i<n-1)
            dp[i] =  max(dp[i], dp[i+1]);
    }

    cout<<dp[0]<<endl;
    return 0;
}