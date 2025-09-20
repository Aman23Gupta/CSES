#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n, x; cin>>n>>x;
    vector<int> a(n,0);

    for(int i=0; i<n;i++) {
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for(int i=0,j=n-1; i<=j; j--) {
        if(a[j]+a[i] <= x) {
            i++;
        }
        ans++;
    }

    cout<<ans<<endl;

    return 0;
}

