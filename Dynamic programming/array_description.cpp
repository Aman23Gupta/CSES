#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main () {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    vector<int> a(n);
    int MOD = 1e9+7;

    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    if(a[0]!=0) dp[1][a[0]] = 1;
    else {
        for(int i=1;i<=m;i++) {
            dp[1][i] = 1;
        }
    }

    for(int i=1;i<n;i++) {
        if(a[i]!=0) {
            for(int j=max(1LL,a[i]-1); j<=min(m, a[i]+1); j++) {
                dp[i+1][a[i]] += dp[i][j];
                dp[i+1][a[i]] %= MOD;
            }

            continue;
        }

        for(int j=1;j<=m;j++) {
            for(int k=max(1LL,j-1); k<=min(m,j+1); k++) {
                dp[i+1][j] += dp[i][k];
                dp[i+1][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=m;i++) {
        ans += dp[n][i];
        ans %= MOD;
    }

    cout<<ans<<endl;
    return 0;
}
