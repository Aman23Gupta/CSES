#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> dp(1e5+1, 0);


int32_t main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=1e5; j > 0; j--) {
            if(j-a[i]>=0) {
                dp[j] = dp[j] || dp[j-a[i]];
            }
        }
    }

    vector<int> ans;

    for(int i = 1; i < 1e5+1; i++) {
        if(dp[i] == 1) ans.push_back(i);
    }

    cout<<ans.size()<<endl;

    for(int i : ans) cout<<i<<" ";

    cout<<endl;
    return 0;
}