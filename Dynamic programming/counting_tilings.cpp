#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n,m; cin >> n >> m;
    int MOD = 1e9+7;

    vector<vector<int>> dp(m+1, vector<int>(1 << n, 0));
    dp[0][0] = 1;

    vector<int> vp;

    for(int i=0; i<(1<<n); i++) {
        bool f = 1;
        int count = 0;
        for(int j=n-1;j>=0;j--) {
            if((1 & (i>>j)) == 0) {
                count++;
            }
            else {
                if(count%2!=0) {
                    f = 0;
                    break;
                }

                count=0;
            }
        }

        if(count%2!=0) {
            f = 0;
        }

        if (f) {
            vp.push_back(i);
        }
    }
    
    for(int i=0;i<m;i++) {
        for(int j = 0; j<(1<<n); j++) {
            if(dp[i][j] > 0) {
                for (int validMask : vp) {
                    if((j & validMask) == j) {
                        //cout<<j<<" "<<validMask<<"\n";
                        int nextMask = j ^ validMask;
                        dp[i+1][nextMask] += dp[i][j];
                        dp[i+1][nextMask] %= MOD;
                    }
                }
            }
        }
    }

    cout<<dp[m][0]<<endl;
    return 0;
}