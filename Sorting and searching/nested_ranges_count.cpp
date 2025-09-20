#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> bit;
map<int,int> idx;

void update(int i, int val) {
    while(i < bit.size()) {
        bit[i] += val;
        i += i&-i;
    }
}

int sum(int i) {
    int ans = 0;

    while(i > 0) {
        ans += bit[i];
        i -= i&-i;
    }

    return ans;
}

void solve(vector<vector<int>>& a) {
    bit.clear();
    int n = a.size();
    bit.resize(n+1,0);

    vector<int> ans(n, 0);

    for(int i=0; i<n; i++) {
        int count = sum(idx[-a[i][1]]);
        ans[a[i][2]] = count;
        update(idx[-a[i][1]], 1);
    }

    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
    return;
}

int32_t main() {
    int n; cin>>n;
    vector<vector<int>> a, b;

    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({y, -x, i});
        b.push_back({x, -y, i});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0;i<n;i++) idx[b[i][0]] = n-i;
    solve(a);

    idx.clear();
    for(int i=0;i<n;i++) idx[a[i][0]] = n-i;
    solve(b);

    return 0;
}