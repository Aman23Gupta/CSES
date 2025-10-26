#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n, m; cin >> n >> m;
    vector<int> a(n, 0);
    for(int i=0; i<n; i++) cin >> a[i];

    vector<pair<int,int>> dp(1 << n);
    dp[0] = {1, 0};
    for(int i=1; i<1<<n; i++) {
        dp[i] = {21, 0};
        for(int j=0; j<n; j++) {
            if((i>>j)&1) {
                int lastset = i^(1<<j);

                if(dp[lastset].second + a[j] <= m) {
                    dp[i] = min(dp[i], {dp[lastset].first, dp[lastset].second + a[j]});
                }
                else {
                    dp[i] = min(dp[i], {dp[lastset].first+1, min(dp[lastset].second , a[j])});
                }
            }
        }
    }

    cout<<dp[(1<<n)-1].first<<endl;
    return 0;

}