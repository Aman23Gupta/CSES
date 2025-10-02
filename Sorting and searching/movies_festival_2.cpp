#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n,k; cin>> n >> k;
    vector<pair<int,int>> time(n);

    for(int i=0; i<n; i++) {
        int a,b; cin >> a >> b;
        time[i] = {b,a};
    }

    sort(time.begin(), time.end());
    multiset<int> st;
    int bad = 0;

    for(int i=0;i<n;i++) {
        auto it = st.lower_bound(-time[i].second);
        if (it == st.end() && st.size() < k) {
            st.insert(-time[i].first);
        }
        else if (it != st.end()) {
            st.erase(it);
            st.insert(-time[i].first);
        }
        else {
            bad++;
        }
    }

    cout<<n-bad<<endl;
    return 0;
}