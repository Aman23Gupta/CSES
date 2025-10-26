#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n,w; cin>>n>>w;
    vector<int> dp(w+1, 0);
    vector<int> a(n, 0), b(n, 0);

    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    for(int i=0; i<n; i++) {
        cin>>b[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        vector<int> tmp(w+1, 0);
        for(int j=0; j<=w; j++) {
            if(j - a[i] >= 0) {
                tmp[j] = max(b[i] + dp[j-a[i]], dp[j]);
                ans = max(ans, tmp[j]);
            }
            else {
                tmp[j] = dp[j];
            }
        }

        // for(int j=0;j<=w;j++) cout<<tmp[j]<<" ";
        // cout<<'\n';

        dp = tmp;
    }

    cout<<ans<<"\n";
    return 0;
}

/*

*/