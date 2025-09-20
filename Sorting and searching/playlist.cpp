#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    map<int, int> m;
    int j=0, ans = 0;
    for(int i=0;i<n;i++) {
        if(m.count(v[i])) {
            j = max(j,m[v[i]]+1);
        }
        m[v[i]] = i;
        //cout<<i<<" "<<j<<"\n";
        ans = max(ans, i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}