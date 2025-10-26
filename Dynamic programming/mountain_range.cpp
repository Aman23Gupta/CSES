#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin>>n;

    vector<int> a(n), dp(n+1, 1);
    for(int i=0;i<n;i++) cin>>a[i];

    stack<int> st;
    int ans = 0;

    a.push_back(INT_MAX);

    for(int i=0; i<n+1; i++) {
        while(!st.empty() && a[st.top()] < a[i]) {
            dp[i] = max(dp[i], dp[st.top()] + 1);
            int idx = st.top();
            st.pop();
            if(!st.empty() && a[st.top()] > a[idx])
                dp[st.top()] = max(dp[idx] + 1, dp[st.top()]);
        }
        st.push(i);
    }
    for(int i=0;i<n;i++) {
        ans = max(dp[i], ans);
    }

    cout<<ans<<endl;
    return 0;
}