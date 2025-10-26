#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<string> a(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int mod = 1e9+7;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    if(a[0][0] == '.') 
        dp[0][0] = 1;

    for(int i=1; i<n; i++) {
        if(a[i][0] == '.')
            dp[i][0] += dp[i-1][0];
    }

    for(int j=1; j<n; j++) {
        if(a[0][j] == '.')
            dp[0][j] += dp[0][j-1];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(a[i][j] == '*') continue;            
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= mod;
        }
    }

    cout<<dp[n-1][n-1]<<endl;

    return 0;
}