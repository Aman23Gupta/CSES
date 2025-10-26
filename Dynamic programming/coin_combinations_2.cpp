#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n,sum; cin >> n >> sum;
    vector<int> dp(sum+1, 0);
    vector<int> coins(n);
    dp[0] = 1;

    int mod = 1e9+7;

    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    for(int c : coins) {
        for(int i=1; i<sum+1; i++) {
            if(i - c >= 0) {
                dp[i] += dp[i-c];
                dp[i] %= mod; 
            }
        }
    }

    cout << dp[sum] << endl;

    return 0;
}