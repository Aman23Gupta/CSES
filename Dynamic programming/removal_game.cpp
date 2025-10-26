#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<vector<int>> dp;

int go(int i, int j, vector<int>& a) {
    if(i>j) return 0;
    //cout<<i<<" "<<j<<endl;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = max(a[i] - go(i+1, j, a), a[j] - go(i, j-1, a));
    return dp[i][j] = ans;
}

int32_t main() {
    int n; cin >> n;
    dp.resize(n, vector<int>(n, -1));

    vector<int> a(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        sum+=a[i];
    }

    cout<<(sum+go(0,n-1,a))/2<<endl;

    return 0;
}