#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n, k; cin>>n>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    map<int, int> m;
    m[0] = 1;
    int sum = 0, ans = 0;
    for(int i=0;i<n;i++) {
        sum += a[i];
        if(m.count(sum-k))
            ans += m[sum-k];
        m[sum]++;
    }

    cout<<ans<<endl;
    return 0;
}