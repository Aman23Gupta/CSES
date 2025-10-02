#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<int> a(n);
    int total = 0;
    for(int i=0;i<n;i++) {
        int x,y; cin>>x>>y;
        a[i] = x;
        total += y;
    }

    sort(a.begin(), a.end());
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        total -= sum;
    }

    cout<<total<<"\n";

    return 0;
}