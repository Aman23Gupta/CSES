#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin>>a[i];
    }

    int j = 0, ans = 0;
    map<int,int> m;
    for(int i=0;i<n;i++) {
        if(m.count(a[i])) {
            j = max(j, m[a[i]]+1);
        }
        ans += i-j+1;
        m[a[i]] = i;
    }

    cout<<ans<<endl;

    return 0;
}