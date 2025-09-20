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

    multiset<int> order;

    for(int i=0;i<n;i++) {
        auto it = order.upper_bound(a[i]);
        if(it != order.end()) {
            order.erase(it);
        }

        order.insert(a[i]);
    }

    cout<<order.size()<<endl;

    return 0;
}