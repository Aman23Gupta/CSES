#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
vector<vector<int>> dp(501, vector<int>(501, INT_MAX));

// int go(int a, int b) {
//     if(a==b) return 0;
//     if(b<=0||a<=0) return 0;

//     if(dp[a][b] != -1) return dp[a][b];
//     int ans = INT_MAX;
//     for(int i=1; i<max(a,b)/2+1; i++) {
//         if(i < a)
//             ans = min(ans, go(a-i, b) + go(i, b) + 1);
//         if(i < b)
//             ans = min(ans, go(a, b-i) + go(a, i) + 1);
//     }

//     return dp[a][b] = ans;
// }

int32_t main() {
    int a, b; cin >> a >> b;

    for(int i=0;i<=min(a,b);i++) dp[i][i] = 0;
    for(int i=0; i<=a; i++) {
        for(int j=0; j<=b; j++) {
            for(int k=1; k<max(i,j)/2+1;k++) {
                if(i-k > 0)
                    dp[i][j] = min(dp[i-k][j] + dp[k][j] + 1, dp[i][j]);
                if(j-k > 0)
                    dp[i][j] = min(dp[i][k] + dp[i][j-k] + 1, dp[i][j]);
            }
        }
    }

    cout<<dp[a][b]<<endl;

    return 0;
}