#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    vector<pair<int,int>> start, end;
    vector<int> ans(n,0);
    set<int> st;
    int total = 0;
    for(int i=0; i<n; i++) {
        int x, y; cin>>x>>y;
        start.push_back({x, i});
        end.push_back({y, i});
        st.insert(i+1);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    for(int i=0,j=0;i<n;i++) {
        while(end[j].first < start[i].first) {
            st.insert(ans[end[j].second]);
            j++;
        }

        int it = *st.begin();
        //cout<<it<<" ";
        ans[start[i].second] = it;
        st.erase(it);
        total = max(total, it);
    }

    cout<<total<<endl;

    for(int i=0; i<n; i++) {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}