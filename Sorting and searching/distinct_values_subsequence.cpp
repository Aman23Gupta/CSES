#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int MOD = 1e9+7;

int32_t main () {
    int n; cin >> n;
    vector<int> a(n), two_pow(n+1,0);

    two_pow[0] = 1;
    map<int,int> m;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        m[a[i]]++;
    }

    int ans = 1;
    
    for(auto k : m) {
        ans = (ans * (k.second + 1))%MOD;
    }
    cout<<ans-1<<endl;
    return 0;
}