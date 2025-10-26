#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> bit;
int MOD = 1e9+7;

void update(int i, int val) {
    while(i<=(int)bit.size()) {
        bit[i] += val;
        bit[i] %= MOD;
        i += i&-i;
    }
}

int sum(int i) {
    int ans = 0;
    while(i>0) {
        ans += bit[i];
        ans %= MOD;
        i -= i&-i;
    }

    return ans;
}

int32_t main() {
    int n; cin>>n;
    vector<int> a(n);
    bit.resize(n+1, 0);
    map<int,int> m;
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }

    vector<int> v(n);
    v = a;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
        m[v[i]] = i+1;
    }

    for(int i=0; i<n; i++) {
        int val = (sum(m[a[i]]-1) + 1)%MOD;
        update(m[a[i]], val);
    }

    cout<<sum(n)<<endl;

    return 0;
}