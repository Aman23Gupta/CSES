#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    int n,m; cin>>n>>m;
    vector<int> num(n), pos(n);
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        num[x-1] = i;
        pos[i] = x-1;
    }

    int count = 1;
    for(int i=0;i<n-1;i++) {
        if(num[i] > num[i+1]) {
            count++;
        }
    }

    while(m--) {
        int a,b; cin>>a>>b;
        a--; b--;

        set<pair<int,int>> s;
        if(pos[a] != n-1)
            s.insert({pos[a], pos[a]+1});
        if(pos[a] != 0)
            s.insert({pos[a]-1, pos[a]});
        if(pos[b] != n-1)
            s.insert({pos[b], pos[b]+1});
        if(pos[b] != 0)
            s.insert({pos[b]-1, pos[b]});

        int before = 0, after = 0;

        for(auto x : s) {
            if(num[x.first] > num[x.second]) before++;
        }

        swap(pos[a], pos[b]);

        num[pos[a]] = a;
        num[pos[b]] = b;

        for(auto x : s) {
            if(num[x.first] > num[x.second]) after++;
        }

        count += after - before;
        cout<<count<<endl;
    }

    return 0;
}