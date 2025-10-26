#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    int MOD = 1e9+7;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<=6;j++) {
            if(i-j>=0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }


    cout<<dp[n]<<endl;
    return 0;
}