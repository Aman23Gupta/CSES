#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n";

int32_t main() {
    int n, sum; cin>>n>>sum;
    vector<int> dp(sum+1,1e18);
    vector<int> coins(n);
    dp[0] = 0;

    for(int i=0;i<n;i++) cin>>coins[i];

    for(int i=0;i<n;i++) {
        for(int j=1;j<=sum;j++) {
            if(j-coins[i] >= 0) {
                dp[j] = min(dp[j], dp[j-coins[i]] + 1);
            }
        }
    }

    // for(int i=0;i<=sum;i++) cout<<dp[i]<<" ";

    // cout<<endl;
    if(dp[sum] == 1e18) {
        cout<<-1<<endl;
    }
    else  {
        cout<<dp[sum]<<endl;
    }

    return 0;
}