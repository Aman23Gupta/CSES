#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n,m; cin>>n>>m;
    multiset<int> tickets;
    vector<int> customers(m);

    for(int i=0;i<n;i++) {
        int x; cin>>x;
        tickets.insert(x);
    }

    for(int j=0;j<m;j++) {
        int x; cin>>x;
        customers[j] = x;
    }

    for(int i=0;i<m;i++) {
        auto it = tickets.upper_bound(customers[i]);
        if(it == tickets.begin()) {
            cout<<-1<<endl;
        }
        else {
            cout<<*(--it)<<endl;
            tickets.erase(it);
        }
    }
}