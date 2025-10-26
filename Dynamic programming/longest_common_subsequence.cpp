#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n,m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i]==b[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else {
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    vector<int> ans;
    int i = n, j = m;
    while(dp[i][j]!=0) {
        if(a[i-1] == b[j-1]) {
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] == dp[i][j]) {
                i--;
            }
            else if(dp[i][j-1]==dp[i][j]) {
                j--;
            }
        }
    }

    cout<<dp[n][m]<<endl;
    reverse(ans.begin(), ans.end());

    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }

    cout<<endl;

    return 0;
}