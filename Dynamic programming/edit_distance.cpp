#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    string a,b;
    cin>>a>>b;

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<n+1;i++) dp[i][0] = i;

    for(int i=1;i<m+1;i++) dp[0][i] = i;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j];
            }
            else {
                dp[i+1][j+1] = 1 + min(dp[i][j+1], min(dp[i][j], dp[i+1][j]));;
            }
        }
    }

    // for(int i=1;i<n+1;i++) {
    //     for(int j=1;j<m+1;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }

    cout<<dp[n][m]<<endl;

    return 0;
}