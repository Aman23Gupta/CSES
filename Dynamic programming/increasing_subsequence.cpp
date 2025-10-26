#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> inc;

    for(int i=0; i<n; i++) {
        auto it = lower_bound(inc.begin(), inc.end(), a[i]);

        if(it == inc.end()) {
            inc.push_back(a[i]);
        }
        else {
            int idx = it - inc.begin();
            inc[idx] = a[i];
        }
    }

    cout<<inc.size()<<endl;

    return 0;
}