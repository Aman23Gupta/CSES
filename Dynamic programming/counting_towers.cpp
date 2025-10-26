#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n";

vector<vector<int>> dp(1e6+1, vector<int>(2, 0));
int MOD = 1e9+7;

int32_t main() {
    int t; cin >> t;
    dp[1e6][0] = 1;
    dp[1e6][1] = 1;
    for(int i=1e6-1; i>0; i--) {
        dp[i][0] = (dp[i+1][1] + 2*dp[i+1][0])%MOD;
        dp[i][1] = (4*dp[i+1][1] + dp[i+1][0])%MOD;
    }

    while (t--) {
        int n; cin >> n;
        cout<<(dp[1e6-n+1][1] + dp[1e6-n+1][0])%MOD<<endl;
    }

    return 0;
}

