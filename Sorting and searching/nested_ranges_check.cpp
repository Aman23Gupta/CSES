#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool comp1(pair<pair<int, int>,int> a, pair<pair<int, int>,int> b) {
    return a.first.first < b.first.first || (a.first.first == b.first.first && a.first.second > b.first.second);
}

int32_t main() {
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> a,b;
    vector<int> ans_a(n, 0), ans_b(n, 0);
    for(int i=0;i<n;i++) {
        int x,y; cin>>x>>y;
        a.push_back({{y,x},i});
        b.push_back({{x,y},i});
    }

    sort(a.begin(), a.end(), comp1); //smallest end than biggest start
    sort(b.begin(), b.end(), comp1); //smallest start than biggest end

    set<int> s1, s2;

    for(int i=0;i<n;i++) {
        auto it1 = s1.lower_bound(a[i].first.second);
        if(it1 != s1.end()) ans_a[a[i].second] = 1;
        s1.insert(a[i].first.second);

        auto it2 = s2.lower_bound(b[i].first.second);
        if(it2 != s2.end()) ans_b[b[i].second] = 1;
        s2.insert(b[i].first.second);
    }

    for(int i=0;i<n;i++) cout<<ans_a[i]<<" ";
    cout<<endl;

    for(int i=0;i<n;i++) cout<<ans_b[i]<<" ";
    cout<<endl;

    return 0;
}