#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> pref(n+1,0);

    for(int i=0; i<n; i++) {
        int x; cin >> x;
        pref[i+1] = pref[i] + x;
    }

    multiset<int> bucket;

    for(int i=a;i<=b;i++) {
        bucket.insert(-pref[i]);
        //cout<<pref[i]<<" ";
    }

    //cout<<"\n";

    int ans = -1e18, curr = 0;
    for(int i=1;i+a-1<=n;i++) {
        curr = *bucket.begin();
        //cout<<-curr<<" "<<pref[i+a-1]<<endl;
        ans = max(ans, -curr - pref[i-1]);
        auto it = bucket.find(-pref[i+a-1]);
        bucket.erase(it);
        if(i+b<=n) {
            bucket.insert(-pref[i+b]);
        }
    }

    cout<<ans<<endl;
    return 0;
}