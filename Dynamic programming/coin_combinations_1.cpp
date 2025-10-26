#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n,sum; cin >> n >> sum;
    vector<int> coins(n);
    vector<int> dp(sum+1, 0);
    int mod = 1e9+7;
    dp[0] = 1;

    for(int i=0; i<n; i++) cin>>coins[i];

    for(int i=1; i<sum+1; i++) {
        for(int c: coins) {
            if(i-c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= mod;
            }
        }
    }

    cout<<dp[sum]<<endl;
    return 0;
}