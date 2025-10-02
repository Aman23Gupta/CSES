#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    map<int, int> m;
    m[0] = 1;
    int sum = 0, ans = 0;
    for(int i=0;i<n;i++) {
        sum = (n+(sum+a[i])%n)%n;
        if(m.count(sum))
            ans += m[sum];
        m[sum]++;
    }

    cout<<ans<<endl;
    return 0;
}